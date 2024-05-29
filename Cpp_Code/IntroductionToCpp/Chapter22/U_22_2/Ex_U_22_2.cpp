/*
    We have to implement functions and classes to that the following program has proper error handling:

    StrChk s1("First"), s2("Sec");

    StrChk s3 = s1 + s2;
       
    s3[10] = 'a'; // Throw IndexError

    s3.show();


*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Err_Rpt
{
private:
    string msg;
public:
    Err_Rpt(const char*m) : msg(m) {}
    void show_err_msg() {cout << msg << "\n";}
};

class StrChk
{
private:
    string str;
public:
    StrChk(const string& init_str) : str(init_str) 
    {
        if (str.length() >= 10)
        {
            throw Err_Rpt("LengthError : Initiialized length surpasses 10 characters");
        }
    }

    StrChk& operator+(StrChk& st2);
    char& operator[](long unsigned int i);
    void show() {cout << str << "\n";}
};

StrChk& StrChk::operator+(StrChk& st2)
{
    if (str.length() + st2.str.length() >= 10)
    {
        throw Err_Rpt("LengthError: Sum length surpasses 10 characters\n");
    }

    this -> str += st2.str;

    return *this;
}

char& StrChk::operator[](long unsigned int i)
{
    if (i > str.length()) // We don't allow changing the null terminator either
    {
        throw Err_Rpt("IndexError : Index out of bounds\n");
    }
    return this->str[i];
}

int main()
{
    try
    {
       StrChk s1("First"), s2("Second");

       StrChk s3 = s1 + s2;
       
        s3[4] = 'a';

        s3.show();

    }
    catch(Err_Rpt err)
    {
       err.show_err_msg();
    }
    
    return 0;
}
