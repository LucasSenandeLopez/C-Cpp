/*
    We are proposed to write a program that tells us how many characters of each type
    are between the two instances of '*'
*/
#include <iostream>

using namespace std;

int main()
{
    char ch;
    unsigned int digits = 0;
    unsigned int letters = 0;
    unsigned int others = 0;
    unsigned int star_count = 0;

    cout << "Input a chain of characters with two '*'s: \n";
    // *D2Efg_#!*345
    do
    {
        ch = (char)cin.get();

        if (star_count == 1)
        {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
                ++letters;
            } else if (ch >= '0' && ch <= '9'){
                ++digits;
            } else {
                ++others;
            }

        } else if (star_count == 2){

            --others;
            break;
        }

        if (ch == '*') {++star_count;}

    } while (ch != '\n');
    
    if (star_count < 2)
    {
        cout << "There were not two stars in that string. \n";

    } else {

        cout << digits << " digits, along with " << letters <<\
            " letters and " << others << " other characters were between the two '*'s. \n";
    }

    return 0;
}
