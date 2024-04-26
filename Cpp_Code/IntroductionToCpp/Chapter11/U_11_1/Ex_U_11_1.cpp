
#include <iostream>

//using namespace std
using std::cout;
using std::cin;

int int_max_min(int int_1, int int_2, int int_3);

int main()
{
    int num_1;
    int num_2;
    int num_3;    

    cout << "Enter three numbers: \n";
    cin >> num_1 >> num_2 >> num_3;

    cout << "F(" << num_1 << ", " << num_2 << ", " << num_3 << ") = " <<\
        int_max_min(num_1, num_2, num_3) << " \n";

    return 0;
}

int int_max_min(int int_1, int int_2, int int_3)
{

    if(int_1 + int_2 == int_3){return (int_1 > int_2)*int_1 + (int_1 <= int_2)*int_2;}

    return (int_3 > int_2)*int_2 + (int_3 <= int_2)*int_3;
}