/*
    We are proposed to create a hierarchy of classes that when sent to cout, prints the private
    values of each class
*/
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ostream;

class Person
{
private:
    string name;
public:
    Person(const string& init_name) : name(init_name){};
    friend ostream& operator<<(ostream& out, Person& person);
    virtual void give(ostream& out) {out << name;}
};


ostream& operator<<(ostream& out, Person& person)
{
    person.give(out);
    return out;
}

class Student : public Person
{
private:
    int id;
public:
    Student(const string& init_name, int init_id) : Person(init_name) {id = init_id;}
    virtual void give(ostream& out) override;
    friend ostream& operator<<(ostream& out, Student& student);
};

void Student::give(ostream& out)
{
    Person::give(out);
    out << " " << id;
}


ostream& operator<<(ostream& out, Student& student)
{
    student.give(out);
    return out;    
}


class Phd_Student : public Student
{
private:
    string thesis_name;
public:
    Phd_Student(const string& init_name, int init_id, const string& init_thesis_name) :\
        Student(init_name, init_id) {thesis_name = init_thesis_name;}

    virtual void give(ostream& out) override;
    friend ostream&  operator<<(ostream& out, Phd_Student& student);
};

void Phd_Student::give(ostream& out)
{
    Student::give(out);
    out << " " << thesis_name;
}


ostream& operator<<(ostream& out, Phd_Student& student)
{
    student.give(out);
    return out;
}

int main()
{
    Person per("One");
    Student st("Two", 2);
    Phd_Student phd("Three", 3, "Th");

    vector<Person*> v(3);
    v[0] = &per;
    v[1] = &st;
    v[2] = &phd;

    for(long unsigned int i = 0; i < v.size(); i++)
    {
        cout << *v[i] << "\n";
    }
    return 0;
}
