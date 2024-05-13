/*
    We are proposed to simulate the functionality of a warehouse
*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

class Warehouse
{
private:
    vector<unsigned long> codes;
    vector<unsigned long> quantities;

public:
    void reg(unsigned long code, unsigned long quantity);
    void order(unsigned long code, unsigned long quantity);
    void show(unsigned long code);
};

void Warehouse::reg(unsigned long code, unsigned long quantity)
{
    
    for(unsigned long existent_code : codes)
    {
        if(code == existent_code)
        {
            cout << "This product has already been registered \n";
            return;
        }
    }

    codes.push_back(code);
    quantities.push_back(quantity);

    cout << "The product with ID: " << code;
    cout << " and quantity: " << quantity << " has been registered\n\n";

    return;
}

void Warehouse::order(unsigned long code, unsigned long quantity)
{

    unsigned long i;

    for (i = 0; i < (unsigned long)codes.size(); ++i)
    {
        if (codes[i] == code)
        {
            if (quantities[i] >= quantity)
            {
                quantities[i] -= quantity;
                cout << "Ordered " << quantity << " products of ID " << code <<\
                "\nThere is a total of " << quantities[i] << " such products remaining\n\n";

                return;

            } else {

                cout << "There are not enough products to fill the order\n\n";
                return;
            }             
        }
    }

    cout << "Product with ID " << code << " not found\n\n"; 
    return;
}

void Warehouse::show(unsigned long code)
{

    unsigned long i;

    for (i = 0; i < (unsigned long)codes.size(); ++i)
    {
        if (codes[i] == code)
        {
            cout << "There are " << quantities[i] << " products of ID " << code << "\n";
            return;         
        }
    }

    cout << "Product with ID " << code << " not found\n"; 
    return;
}


int main()
{

    Warehouse whs;

    whs.reg(1050, 12);
    whs.reg(1051, 14);
    whs.reg(1054, 19);
    whs.reg(2022, 120);

    whs.order(1050, 6);
    whs.order(1051, 16);
    whs.order(1054, 13);

    whs.show(1054);

    return 0;
}
