/* 
    The exercise is just correcting the code; as it seems to only be about declarations and definitions
    I am going to print the result in the console

*/
#include <iostream>

#define NUM 30

int main()
{

    const int a = 10;
    float f = 1.23f;
    int i = (int)f;
    
    std::cout << i + NUM + 2 + a<< "\n\n";  

    return 0;

}