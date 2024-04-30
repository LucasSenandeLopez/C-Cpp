/*
    We are proposed to write a function that from two strings, returns a pointer to 
    the longest part in the first string that does NOT contain any character
    in the second string and if none is received, return a nullptr
*/
#include <iostream>
#include <cstring>

//using namespace std
using std::cout;
using std::cin;

char *uncontained_ptr(char str_1[], char str_2[]);

int main()
{
    const unsigned int LENGTH = 100;
    char string_1[LENGTH];
    char string_2[LENGTH];

    cout << "Enter two strings: \n";

    cin.getline(string_1, LENGTH);
    cin.getline(string_2, LENGTH);


    char *pointed_str = uncontained_ptr(string_1, string_2);

    if (pointed_str != nullptr)
    {
        cout << "The longest part of the first string without characters in the second one starts at :" <<\
            pointed_str << " \n";
    }

    return 0;
}

char *uncontained_ptr(char str_1[], char str_2[])
{

    unsigned int len_1 = (unsigned int)strlen(str_1);
    unsigned int len_2 = (unsigned int)strlen(str_2);

    unsigned int end = len_1;
    unsigned int ptr = 0;
    unsigned int isequal_flag;
    unsigned int length = 0;
    unsigned int temp_length = 0;

    for (unsigned int i = 0; i < len_1; ++i)
    {    
        isequal_flag = 0;

        for (unsigned int j = 0; j < len_2; ++j)
        {

            if (str_1[i] == str_2[j]) 
            {
                isequal_flag = 1;

                break;
            } 
        }

        if (isequal_flag) 
        {


            if ((!length) || (length < temp_length))
            {
                length = temp_length;
                end = i;
            } 

            temp_length = 0;

        } else {

            ++temp_length;
        }
    }

    if (temp_length > length){length = temp_length;}    

    ptr = end - length;

    if(length)
    {
        return str_1 + ptr;
    }

    return nullptr;

}