/*
    We are proposed to build a function that returns from two string object
    references and a char, the one that contains that char the most
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;


string str_contains(string& str_1, string& str_2, char cont_char);

int main()
{

    string str_1;
    string str_2;
    char chr;

    cout << "Enter two strings and then a character: \n";

    getline(cin, str_1);
    getline(cin, str_2);
    cin.get(chr);

    cout << "The string that contains \'" << chr << "\' the most is \"" <<\
        str_contains(str_1, str_2, chr) << "\"\n";

    return 0;
}

string str_contains(string& str_1, string& str_2, char cont_char)
{
    unsigned int counter_1 = 0;
    unsigned int counter_2 = 0;

    for(char element : str_1)
    {
        if(element == cont_char){++counter_1;}
    }

    for(char element : str_2)
    {
        if(element == cont_char){++counter_2;}
    }


    if (counter_1 > counter_2)
    {
        return str_1;
        
    } else if (counter_2 > counter_1) {

        return str_2;

    } else if ((counter_1 == counter_2) && counter_1 > 0){

        return string("[Both!]");
    }

    return string("[N/A; character not found in any]");
}