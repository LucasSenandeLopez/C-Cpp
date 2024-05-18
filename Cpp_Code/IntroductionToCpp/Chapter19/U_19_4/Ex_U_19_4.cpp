/*
    We are proposed to build functionality so the following main function works:

    Student st1(10);
    Student::Course c1(100, 7.5), c2(200, 3.5), c3(300, 5.5);

    st1.add(&c1);
    st1.add(&c2);
    st1.add(&c3);

    Student st2(st1);

    cout << st2;

*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::ostream;


class Student
{
public:
    Student(int init_st_code);
    ~Student() = default;
    Student(Student& st_init);
    class Course
    {
        private:
            int code;
            double grd;

        public:
            friend ostream& operator<<(ostream& out, Course course);

        public:
        Course(int init_code, double init_grd) : code(init_code), grd(init_grd){}
        ~Course() = default;
        
    };

    friend ostream& operator<<(ostream& out, const Student& student);
    void add(Course* new_course);
private:
    int st_code;
    vector<Course*> v_crs;
    
};

ostream& operator<<(ostream& out, Student::Course course)
{
    out << "Course ID: " << course.code << "\nGrade: " << course.grd << "\n";
    return out;
}


Student::Student(int init_st_code)
{
    this->st_code = init_st_code;
    this-> v_crs = vector<Course*>();
}

void Student::add(Course* new_course)
{
    this->v_crs.push_back(new_course);
    return;
}

ostream& operator<<(ostream& out, const Student& student)
{

    out << "Student ID: " << student.st_code << "\n________________\n";
    
    for (auto& course_ptr : student.v_crs)
    {
        out << (*course_ptr);
    }
    
    out << "\n";
    return out;
}

Student::Student(Student& st_init)
{

    st_code = st_init.st_code;
    v_crs = st_init.v_crs;

}

int main()
{
    Student st1(10);
    Student::Course c1(100, 7.5), c2(200, 3.5), c3(300, 5.5);

    st1.add(&c1);
    st1.add(&c2);
    st1.add(&c3);

    Student st2(st1);

    cout << st2;
    return 0;
}
