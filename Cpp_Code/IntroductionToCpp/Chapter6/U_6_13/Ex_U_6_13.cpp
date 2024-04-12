/*
    We are proposed to count the number of bits of an integer that are set to 1
*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int num;
    unsigned int count = 0;

    cout << "Introduce an integer: \n";
    cin >> num;

    for(int i = 0; i < 32; ++i)
    {

        count += (num & 1);
        num >>= 1U;

    }

    cout << "The number has " << count << " bits set to 1 \n";

    return 0;
}
