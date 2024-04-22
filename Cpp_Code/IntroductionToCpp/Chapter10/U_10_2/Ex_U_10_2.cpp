/*
    We are proposed to write a program that reads a string and if it ends with "aa";
    we should reverse it
*/
#include <iostream>

//using namespace std
using std::cout;
using std::cin;
using std::string;

int main()
{
    string str;

    cout << "Enter a string: \n";
    cin >> str;
    cout << str[str.length()];

    if (str.back() == 'a' && str[str.length() - 2] == 'a')
    {
        for (long unsigned int i = str.length(); i > 0LU; --i)
        {
            cout << str[i - 1];

        }
        cout << "\n";
    } else {

        cout << "\"" << str <<"\" does not end with \"aa\"\n";
    }

    return 0;
}
