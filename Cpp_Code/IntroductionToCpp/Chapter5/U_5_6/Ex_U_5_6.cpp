/*

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    long address;

    cout << "Introduce the adress: \n";
    cin >> hex >> address;

    if (address == 255){

        cout << "The adress is broadcast \n";

    } else if(address % 2) {

        cout << "The adress is multicast \n";

    } else {

        cout << "The adress is unicast \n";

    }

    return 0;
}
