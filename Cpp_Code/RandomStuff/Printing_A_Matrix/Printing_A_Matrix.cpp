#include <iostream>

using namespace std;

int main()
{
    int arr[5][5]{0}, *ptr = arr[0];


    for(int i = 0; i < 25; ++i)
    {

        *(ptr + i) = i + 1;

        !((i + 1) %  5) ? (cout << i + 1 << "\n" ) : (cout << i + 1 << "   ");

    }

    cout << "\n\n";

    for(int i = 0; i < 5; ++i)
    {

        for(int j = 0; j < 5; ++j)
        {
            
            cout << arr[i][j] << " ";

        } 

        cout << "\n";
    }   

    return 0;
}
