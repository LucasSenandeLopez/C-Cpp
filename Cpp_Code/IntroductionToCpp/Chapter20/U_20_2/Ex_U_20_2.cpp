/*
    We are proposed to build classes using inheritance so tht the following main function works:

    int main()
    {
        Sphere sph("Blue", 2);

        Circle& c = sph;
        c.show() //It should show colour and VOLUME of the SPHERE

        return 0;
    }

*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Circle
{
protected:
    float radius;
public:
    Circle(float rd) : radius(rd){};
    ~Circle() = default;
    virtual void show() const;
};

class Sphere : public Circle
{
private:
    string colour;
public:

    Sphere(const string& col, float rad) : Circle(rad) {colour = col;}
    ~Sphere() = default;
    virtual void show() const override;
};

void Circle::show() const
{
    cout << "The area of the circle is: " << 3.1415f * radius * radius << "\n";
    return;
}

void Sphere::show() const
{

    cout << "The colour of the sphere is \"" << colour << "\" and its volume is " <<\
        3.1415f * 4.0f * radius * radius * radius / 3.0f << "\n";

    return;
}


int main()
{
    Sphere sph("Blue", 2);

    Circle& c = sph;
    c.show();

    return 0;
}
