/*

    We are proposed to divide the introduced seconds into hours, minutes and seconds
    while using only one variable

*/

#include <iostream>

using namespace std;

int main()
{
    int seconds;

    cout << "Introduce the number of seconds: \n";
    cin >> seconds;

    cout << "The total is: " << seconds/3600 << "h " << (seconds % 3600)/60 << "m " << \
        (seconds % 3600) % 60 << "s \n" ;
        
    return 0;
}
