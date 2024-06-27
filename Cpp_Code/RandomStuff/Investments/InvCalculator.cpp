#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    float avg_purchase_price;
    float dividends_paid;
    int quantity;
    float fees;
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
    void add_position(){};
    
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

    do
    {
        cout << "\nPlease, select an option of the following: \n\n";
        cout << "1: Review a specific position\n";
        cout << "2: Get a general overview\n";
        cout << "3: Edit a specific position\n";
        cout << "4: Add a position\n";
        cout << "5: Terminate the program\n";

        cin >> option;
    } while (option < 1 || option > 5);
        
    switch (option)
    {
    case 1:
        review_position();
        break;

    case 4:
        add_position();
        break;
    case 5:
        break;
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
    cout << "Average Purchase Price: " << position_data[pos_id].avg_purchase_price << "\n";
    cout << "Dividends Paid: " << position_data[pos_id].dividends_paid << "\n";
    cout << "Quantity: " << position_data[pos_id].quantity << "\n";
    cout << "Fees: " << position_data[pos_id].fees << "\n";
    cout << "Net price after dividends and fees: " << position_data[pos_id].price_minus_div_fees << "\n";

}


int main()
{   

    FileAction file("/home/fedesuarez/Documents/CppFiles/investment.txt");
    file.menu();
    return 0;
}
