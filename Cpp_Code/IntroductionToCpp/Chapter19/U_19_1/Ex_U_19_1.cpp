/*
    We have to modify the class T so the following main() function works:

    int main()
    {
        string s1 = "abcdef", s2 = "abc";
        T t1(s1), t2(s2);
        t2 = t1;
        T t3(t2);
        t3.show()
        return 0;
    }

*/
#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::string;
class T
{
private:
    char *s;
public:
    T(string str)
    {
        s = new char[str.size() + 1];
        strcpy(s, str.c_str());
    }

    T(T& str)
    {
       s = new char[strlen(str.s) + 1];
       strcpy(s, str.s); 
    }

    ~T()
    {     
        delete[] s;
    };

    T& operator=(T& str);
    void show();
};

T& T::operator=(T& str)
{
    delete[] this->s;
    this->s = new char[strlen(str.s) + 1];
    strcpy(this->s, str.s);

    return *this;    
}

void T::show()
{
    cout << s << "\n";
}

int main()
{
    string s1 = "abcdef", s2 = "abc";
    T t1(s1), t2(s2);
    t2 = t1;
    T t3(t2);
    t3.show();
       
    return 0;
}
