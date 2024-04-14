/*

    We are proposed to use pointers to display if three negative numbers are in
    succesive ascending order

*/
#include <iostream>

using namespace std;

int main()
{
    int num_1, *ptr_1 = &num_1;
    int num_2, *ptr_2 = &num_2;
    int num_3, *ptr_3 = &num_3;
    
    do
    {
        cout << "Input three negative numbers: \n";
        cin >> *ptr_1 >> *ptr_2 >> *ptr_3;

    } while (*ptr_1 > 0 || *ptr_2 > 0 || *ptr_3 > 0);
    

   switch (*ptr_1 < *ptr_2 && *ptr_2 < *ptr_3)
   {
   case 1:
        cout << *ptr_1 << " < " << *ptr_2 << " < "<< *ptr_3 << " \n";
    break;
   
   default:
        cout << "The numbers are not succesively increasing. \n";
    break;
   }

    return 0;
}