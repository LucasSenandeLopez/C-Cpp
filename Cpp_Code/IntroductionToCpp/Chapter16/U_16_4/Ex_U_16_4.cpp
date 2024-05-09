/*
    We are proposed to create a function template that returns the largest element of 
    a vector class
*/
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template <typename T> T largest_el(vector<T>& elements);


int main()
{
    vector<int> int_vec = {-7, 8, 92, 12, -101, 43, 52};
    vector<string> str_vec = {"abcdefg", "z1234", "Z1234"};

    cout << "The largest number is " << largest_el(int_vec) << " and the largest string is \"" <<\
        largest_el(str_vec) << "\"\n";

    return 0;
}

template <typename T> T largest_el(vector<T>& elements)
{

    T largest = elements[0];
    
    for(size_t i = 1; i < elements.size(); ++i)
    {
        if(largest < elements[i]){largest = elements[i];}
    }

    return largest;
}