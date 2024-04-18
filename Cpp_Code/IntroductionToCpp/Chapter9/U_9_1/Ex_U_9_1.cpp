/*
    We are proposed to write a porgram that reads characters until q is sent or the sum of
    their ASCII values exceeds 500
*/
#include <iostream>

using namespace std;

int main()
{
    unsigned char current_char;
    unsigned int sum = 0;
    unsigned int count = 0;

    do
    {
        cout << "Input a character: \n";
        cin >> current_char;
        cin.get();

        sum += (unsigned int)current_char;
        ++count;

        if (current_char == 'q') {break;}

    } while (sum < 500);
    
    cout << count << " characters were introduced with an ASCII value of " << sum << " \n";

    return 0;
}
