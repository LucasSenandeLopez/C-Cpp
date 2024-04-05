/*

    We have to display how many of three students succeded given a minimum grade to pass
    with the condition that the passing grade cannot be higher than 10

*/

#include <iostream>

using namespace std;

int main()
{
    float min_grade;
    float grade_one;
    float grade_two;
    float grade_three;
    int passing_students;

    cout << "Type in the minimum grade to pass and then the grades of three students: \n";

    cin >> min_grade >> grade_one >> grade_two >> grade_three;

    min_grade = (min_grade <= 10) * min_grade + (min_grade > 10) * 5.0f; 

    grade_one = (grade_one <= 10) * grade_one + (grade_one > 10) * 10.0f;
    grade_two = (grade_two <= 10) * grade_two + (grade_two > 10) * 10.0f;
    grade_three = (grade_three <= 10) * grade_three + (grade_three > 10) * 10.0f;

    passing_students = (grade_one >= min_grade) + (grade_two >= min_grade) + (grade_three >= min_grade);

    cout << "A total of " << passing_students << "/3 students passed \n";

    return 0;

}
