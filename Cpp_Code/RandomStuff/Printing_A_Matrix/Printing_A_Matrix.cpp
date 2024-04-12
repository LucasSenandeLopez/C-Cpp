#include <iostream>

using namespace std;

int main()
{
    int arr[5][5], *ptr = arr[0];


    for(int i = 0; i < 25; ++i)
    {

        *(ptr + i) = i + 1;

        !((i + 1) %  5) ? (cout << i + 1 << "\n" ) : (cout << i + 1 << "   ");

    }

    return 0;
}
