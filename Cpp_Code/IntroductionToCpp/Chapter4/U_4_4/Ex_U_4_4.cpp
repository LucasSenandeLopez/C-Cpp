/*

    We have to display the average of passing grades assuming that at least one does pass

*/

#include <iostream>

using namespace std;

int main()
{
    float min_grade;
    float grade_one;
    float grade_two;
    float grade_three;
    float avg_passing_grade;
    int passing_students;

    cout << "Type in the minimum grade to pass and then the grades of three students: \n";

    cin >> min_grade >> grade_one >> grade_two >> grade_three;

    /*
    This statement ensures that the minimum passing grade 
    is smaller or equal than 10 and if not, it is 5
    */
    min_grade = (min_grade <= 10) * min_grade + (min_grade > 10) * 5.0f; 

    grade_one = (grade_one <= 10) * grade_one + (grade_one > 10) * 10.0f;
    grade_two = (grade_two <= 10) * grade_two + (grade_two > 10) * 10.0f;
    grade_three = (grade_three <= 10) * grade_three + (grade_three > 10) * 10.0f;

    passing_students = (grade_one >= min_grade) + (grade_two >= min_grade) + (grade_three >= min_grade);

    /*
    This statement ensures at least one passes and if no one does,
    the first one does with the min. grade
    */
    grade_one = (passing_students > 0) * grade_one + (passing_students == 0) * min_grade;
    passing_students += (!passing_students);

    avg_passing_grade = ((grade_one >= min_grade) * grade_one + \
        (grade_two >= min_grade) * grade_two + (grade_three >= min_grade) * grade_three) / \
        (float)passing_students;

    cout << "The average passing grade is: " << avg_passing_grade << " \n";

    return 0;

}