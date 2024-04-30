/*
    We are proposed to write a function that counts the lowercase, uppercase and
    numeric characters in a string object
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void count_chars(string str, unsigned int *nums_count, unsigned int *lower_count, unsigned int *upper_count);

int main()
{
    string input_str;
    unsigned int digit_count = 0;
    unsigned int lower_count = 0;
    unsigned int upper_count = 0;

    cout << "Enter a string: \n";
    
    cin >> input_str;

    cout << input_str;

    if ((input_str.length() > 2) && (input_str[0] == 'a') && (input_str[input_str.length() - 1] == 'q'))
    {

        count_chars(input_str, &digit_count, &lower_count, &upper_count);

        cout << "\nIn the string \"" << input_str << "\" there were: \n - ";
        cout << digit_count << " digits, \n - ";
        cout << lower_count << " lowercase letters, \n - ";
        cout << upper_count << " uppercase letters. \n";

        return 0;
    }

    cout << "\nThe string is either too short or it doesn't start with 'a' and end with 'q'. \n";
    return 0;
}

void count_chars(string str, unsigned int *nums_count, unsigned int *lower_count, unsigned int *upper_count)
{

    long unsigned int len = str.length();

    for(long unsigned int i = 0; i < len; ++i)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            ++(*upper_count);

        } else if (str[i] <= 'z' && str[i] >= 'a') {

            ++(*lower_count);

        } else if (str[i] <= '9' && str[i] >= '0') {

            ++(*nums_count);
        }
    }

    return;
}