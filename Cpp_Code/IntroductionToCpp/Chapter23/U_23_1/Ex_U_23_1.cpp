/*
    We are proposed to make a store manager using class templates so the following
    main function works:

    int main()
    {
        Shop<Book> s1;
        s1.add(Book(5,10));
        s1.add(Book(20,30));
        s1.show();

        Shop<CD> s2;
        s2.add(CD("Music_1"));
        s2.add(CD("Music_2"));
        s2.show();

        return 0;
    }
*/
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Book
{
private:
    int code;
    int price;
public:
    Book(int init_code, int init_price) : code(init_code), price(init_price) {};
    void print()
    {
        cout << "Book code: " << code << "; book price: " << price << "€\n";
    }
};


class CD
{
private:
    string name;
public:
    CD(const string& init_name) : name(init_name) {};

    void print()
    {
        cout << "CD name: " << name << "\n";
    }
};

template <typename T> class Shop
{
private:
    vector<T> prod_vec;
public:
    void add(const T& new_member)
    {
        prod_vec.push_back(new_member);
    }

    void show()
    {
        for (T& mem : prod_vec)
        {
            mem.print();
        }
        
    }

};


int main()
{
    Shop<Book> s1;
    s1.add(Book(5,10));
    s1.add(Book(20,30));
    s1.show();

    Shop<CD> s2;
    s2.add(CD("Music_1"));
    s2.add(CD("Music_2"));
    s2.show();

    return 0;
}
