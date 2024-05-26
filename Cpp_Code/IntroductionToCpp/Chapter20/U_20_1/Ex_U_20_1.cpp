/*
    We have to create a three-class hierarchy so we can enter an input for each member
    using the last one
*/
#include <iostream>

using std::cout;
using std::cin;

class Class_A
{
private:
    int num_A;
public:
    virtual void get();
    virtual void show();
};

void Class_A::get()
{
    cout << "Class A input: ";
    cin >> num_A;
}

void Class_A::show()
{
    cout << "Class_A output: " << num_A << "\n";
}


class Class_B : virtual public Class_A
{
private:
    int num_B;
public:
    virtual void show() override;
    virtual void get() override;
};

void Class_B::get()
{
    Class_A::get();
    cout << "Class B input: ";
    cin >> num_B;
    
}

void Class_B::show()
{
    cout << "Class_A output: " << num_B << "\n";
    Class_A::show();
}

class Class_C : virtual public Class_B
{
private:
    int num_C;
public:
    virtual void show() override;
    virtual void get() override;
};

void Class_C::get()
{
    Class_B::get();
    cout << "Class C input: ";
    cin >> num_C;
    
}

void Class_C::show()
{
    cout << "Class_C output: " << num_C << "\n";
    Class_B::show();
}




int main()
{
    Class_C c;
    c.get();

    c.show();
    return 0;
}
