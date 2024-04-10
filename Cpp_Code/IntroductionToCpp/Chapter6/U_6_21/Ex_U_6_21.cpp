/*
    We are proposed to build a program that from an odd positive integer n, 
    displays the sum of the sequence defined as:

    1/(1 * 3) + 1/(3 * 5) + ... + 1/(n-2 * n)

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    float sum = 0.0f;
    do
    {
        cout << "Insert an odd integer greater than or equal to three: \n";
        cin >> n;

    } while (n < 3U || (n % 2U == 0));
    
    for(unsigned int i = 1; i < n; i += 2)
    {
        sum += 1.0f / (float)(i * (i + 2));

    }

    cout << "\nThe sum is: " << sum << " \n\n";

    return 0;
}
