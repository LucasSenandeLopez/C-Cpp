#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

//using namespace std
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ios_base;
using std::ifstream;
using std::ofstream;

struct Position
{
    int ID;    
    string ticker;
    double avg_purchase_price;
    double dividends_paid;
    long unsigned int quantity;
    double fees;
    double price_minus_div_fees;
};

class FileAction
{
private:
    vector<Position> position_data;
    ifstream for_input;
    ofstream for_output;
    const char *filepath;

    
    void review_position();
    void general_review(); 
    void edit_position();
    void add_position();
    void delete_position();
    
public:
    FileAction(const char* path);
    ~FileAction();
    void menu();
};

FileAction::FileAction(const char* path) : filepath(path)
{
    Position pos;

    for_input.open(path, ios_base::in);

    if (for_input.is_open() != true)
    {
        std::cerr << "An error has occurred while trying to read the file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (for_input)
    {
        for_input >> pos.ID;
        for_input >> pos.ticker;
        for_input >> pos.avg_purchase_price;
        for_input >> pos.dividends_paid;
        for_input >> pos.quantity;
        for_input >> pos.fees;
        for_input >> pos.price_minus_div_fees;

        position_data.push_back(pos);
    }

    position_data.pop_back();

    cout << "Current positions: \n";

    for (long unsigned int i = 0; i < position_data.size(); ++i)
    {
        cout << position_data[i].ID << ": " << position_data[i].ticker <<  "\n";
    }
    for_input.close();
}

FileAction::~FileAction()
{
    for_input.close();
    for_output.close();
    cout << "File closed successfully" << std::endl;
}

void FileAction::menu()
{
    long unsigned int option;
    bool flag = true;
    while(flag)
    {
        do
        {
            cout << "\nPlease, select an option of the following: \n\n";
            cout << "1: Review a specific position\n";
            cout << "2: Get a general overview\n";
            cout << "3: Edit a specific position\n";
            cout << "4: Add a position\n";
            cout << "5: Delete a position\n";
            cout << "6: Terminate the program\n";

            cin >> option;
        } while (option < 1 || option > 6);
            
        switch (option)
        {
        case 1:
            review_position();
            break;
        case 2:
            general_review();
            break;
        case 3:
            edit_position();
            break;
        case 4:
            add_position();
            break;
        case 5:
            delete_position();
            break;
        case 6:
            flag = false;
            break;
        }
    }
}

void FileAction::review_position()
{

    long unsigned int pos_id;
    do
    {
        cout << "\nSelect a position ID: \n\n";

        for (long unsigned int i = 0; i < position_data.size(); ++i)
        {
            cout << position_data[i].ID << ": " << position_data[i].ticker <<  "\n";
        }
        cin >> pos_id;
    } while (pos_id < 1 || pos_id > 5);
    

    cout << "\n\n";
    --pos_id;

    cout << "ID: " << position_data[pos_id].ID << "\n";
    cout << "Ticker: " << position_data[pos_id].ticker << "\n";
    cout << "Average Purchase Price: " << std::fixed << std::setprecision(2) << position_data[pos_id].avg_purchase_price << "\n";
    cout << "Dividends Paid: " << std::fixed << std::setprecision(2) << position_data[pos_id].dividends_paid << "\n";
    cout << "Quantity: " << position_data[pos_id].quantity << "\n";
    cout << "Fees: " << std::fixed << std::setprecision(2) << position_data[pos_id].fees << "\n";
    cout << "Net price after dividends and fees: " << std::fixed << std::setprecision(2) << position_data[pos_id].price_minus_div_fees << "\n";

}

void FileAction::general_review()
{
    double result;
    result = 0.0;

    for (long unsigned int i = 0; i < position_data.size(); ++i)
    {
        cout << "Ticker: " << position_data[i].ticker << "\n";
        cout << "Average purchase Price: " << std::fixed << std::setprecision(2) << position_data[i].avg_purchase_price << "\n";
        cout << "Net price after dividends and fees: " << std::fixed << std::setprecision(2) << position_data[i].price_minus_div_fees << "\n\n";

        result += (double)position_data[i].quantity * position_data[i].price_minus_div_fees;
    }

    cout << "The profit barrier for this portfolio is: " << result << "€\n";
}

void FileAction::add_position()
{

    string ticker;
    long unsigned int quantity;
    double fees;
    double divs;
    double price;
    double net_price;

    for_output.open(filepath, ios_base::out | ios_base::app);
    if (for_output.is_open() == false)
    {
        std::cerr << "An error has occurred while opening the file" << std::endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the ticker: \n";
    cin >> ticker;

    cout << "Enter the average purchase price: \n";
    cin >> price;

    net_price = price;

    cout << "Enter the dividends paid per share: \n";
    cin >> divs;
    
    net_price -= divs;

    cout << "Enter the total quantity: \n";
    cin >> quantity;
    
    cout << "Enter the total fees: \n";
    cin >> fees;
    

    net_price += fees / (double)quantity;

    for_output << position_data.size() + 1;
    for_output << "\t";

    for_output << ticker;
    for_output << "\t";

    for_output << price;
    for_output << "\t";

    for_output << divs;
    for_output << "\t";

    for_output << quantity;
    for_output << "\t";

    for_output << fees;
    for_output << "\t";

    for_output << net_price;
    for_output << "\n";

    for_output.close();
    cout << "Data sent to file!\n";
}

void FileAction::edit_position()
{
    long unsigned int position_id;
    long unsigned int quantity_num;
    long unsigned int prev_quantity;
    double prev_price;
    double edit_num;
    double div_num;

    cout << "Select an ID to edit: \n\n";
    do
    {
        for (long unsigned int i = 0; i < position_data.size(); ++i)
        {
            cout << position_data[i].ID << ": " << position_data[i].ticker <<  "\n";
        }
        cin >> position_id;
    } while (position_id < 1 || position_id > position_data.size());
    
    --position_id;

    prev_quantity = position_data[position_id].quantity;

    cout << "Add the quantity added (negative for substraction)\n";
    cin >> quantity_num;
    position_data[position_id].quantity += quantity_num;

    prev_price = position_data[position_id].avg_purchase_price;


    cout << "Enter the purchase price to the new units \
        (If you sold or set quantity to zero, it does nothing)\n";
    cin >> edit_num;

    if (quantity_num > 0)
    {
        position_data[position_id].avg_purchase_price = ((double)prev_quantity * position_data[position_id].avg_purchase_price\
            + (double)quantity_num*edit_num) / double(quantity_num + prev_quantity);

    }

    cout << "\nEnter the new dividend per share\n";
    cin >> div_num;

    position_data[position_id].dividends_paid += div_num;

    cout << "\nEnter the extra fees ";
    cin >> edit_num;
    position_data[position_id].fees += edit_num;

    //We do not add all the dividends because they affect only the pre-bought shares
    position_data[position_id].price_minus_div_fees += edit_num / (double)position_data[position_id].quantity;
    position_data[position_id].price_minus_div_fees -= div_num;
    position_data[position_id].price_minus_div_fees -= (prev_price - position_data[position_id].avg_purchase_price);

    for_output.open(filepath, ios_base::out | ios_base::trunc);

    if (for_output.is_open() == false)
    {
        std::cerr << "The file couldn't be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(long unsigned int i = 0; i < position_data.size(); ++i)
    {
        for_output << position_data[i].ID << "\t";
        for_output << position_data[i].ticker << "\t";
        for_output << position_data[i].avg_purchase_price << "\t";
        for_output << position_data[i].dividends_paid << "\t";
        for_output << position_data[i].quantity << "\t";
        for_output << position_data[i].fees << "\t";
        for_output << position_data[i].price_minus_div_fees << "\n";
    }
    for_output.close();
}

void FileAction::delete_position()
{
    long unsigned int position_id;
    cout << "Select an ID to delete: \n\n";
    do
    {
        for (long unsigned int i = 0; i < position_data.size(); ++i)
        {
            cout << position_data[i].ID << ": " << position_data[i].ticker <<  "\n";
        }
        cin >> position_id;
    } while (position_id < 1 || position_id > position_data.size());

    --position_id;
    position_data.erase(position_data.begin() + (long int)position_id);


    
    for_output.open(filepath, ios_base::out | ios_base::trunc);

    if (for_output.is_open() == false)
    {
        std::cerr << "The file couldn't be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(long unsigned int i = 0; i < position_data.size(); ++i)
    {
        for_output << i + 1 << "\t";
        for_output << position_data[i].ticker << "\t";
        for_output << position_data[i].avg_purchase_price << "\t";
        for_output << position_data[i].dividends_paid << "\t";
        for_output << position_data[i].quantity << "\t";
        for_output << position_data[i].fees << "\t";
        for_output << position_data[i].price_minus_div_fees << "\n";
    }
    for_output.close();


}

int main()
{   

    FileAction file("/home/fedesuarez/Documents/CppFiles/investment.txt");
    file.menu();
    return 0;
}
