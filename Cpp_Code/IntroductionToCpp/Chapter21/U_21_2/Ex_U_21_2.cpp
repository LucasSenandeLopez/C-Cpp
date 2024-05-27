/*
    We are propose to build a program using astraction so that the following main function works:

    int main()
    {
        Book b(1, 2, "pub") ;
        Car c(4, 5, 6);

        Product& p1 = b;
        Product& p2 = c;

        p1.show();
        p2.show();

        return 0;
    }



*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Product
{
protected:
    int code;
    int price;
public:
    Product(int init_code, int init_price) : code(init_code), price(init_price) {};
    virtual void show() const = 0;
};

class Book : public Product
{
private:
    string publisher_name;
public:
    Book(int init_code, int init_price, const string& init_pub_name) : Product(init_code, init_price)
    {
        publisher_name = init_pub_name;
    }

    virtual void show() const override;
};

void Book::show() const
{
    cout << "The book with id " << code << " and a price of " << price << "€ has " << publisher_name <<\
        " as publisher.\n";
}


class Car : public Product
{
private:
    int horsepower;
public:
    Car(int init_code, int init_price, int init_horsepower) : Product(init_code, init_price)
    {
        horsepower = init_horsepower;
    }

    virtual void show() const override;
};

void Car::show() const
{
    cout << "The car with id " << code << " and a price of " << price << "€ has " << horsepower <<\
        " horsepower.\n";
}

int main()
{
    Book b(1, 2, "pub") ;
    Car c(4, 5, 6);

    Product& p1 = b;
    Product& p2 = c;

    p1.show();
    p2.show();  

    return 0;
}
