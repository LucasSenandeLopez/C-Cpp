/*
    We are proposed to define a Date class
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

class Date 
{
private:

unsigned short day;
unsigned short month;
unsigned short year;



public:

void set_date(char datestring[]);
~Date(){cout << "Day: " << day  << "\nMonth: " << month << "\nYear: "<< year << "\n";}

};

void Date::set_date(char datestring[])
{
    int i = 0;
    unsigned short num = 0;

    while (datestring[i] != '/' && datestring[i] != '\0')
    {
        num *= 10;
        num += (unsigned short)(datestring[i] - 48);
        ++i;
    }

    day = num;
    ++i;
    num = 0;

    while (datestring[i] != '/' && datestring[i] != '\0')
    {
        num *= 10;
        num += (unsigned short)(datestring[i] - 48);
        ++i;
    }

    month = num;
    ++i;
    num = 0;

    while (datestring[i] != '/' && datestring[i] != '\0')
    {
        num *= 10;
        num += (unsigned short)(datestring[i] - 48);
        ++i;
    }
    
    year = num;
    ++i;
    num = 0;

    return;
}

int main()
{
    char str[11];
    Date dt;

    cout << "Enter a date in \"dd/mm/yyyy\" format: \n";
    cin.getline(str, 11);

    dt.set_date(str);
    return 0;
}
