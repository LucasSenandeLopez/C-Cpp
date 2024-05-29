/*
    We are proposed to write a class B that contains 5 objects of class A and write
    a program that checks how many times the destructor of A is called if after the third 
    creation, we throw an error
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class A
{
private:
    static inline int el = 0;

public:
    A() 
    {
        
        if(el >= 3)
        {
            throw string("No\n");
        }    
        ++el;
    }

    ~A(){cout << "Object A destroyed with el = " << el << "\n";}
};

class B
{
public:
    A a1;
    A a2;
    A a3;
    A a4;
    A a5;

};

int main()
{
    try
    {
        B b;
    }
    catch(string str)
    {
        cout << str;
    }

    return 0;
}
