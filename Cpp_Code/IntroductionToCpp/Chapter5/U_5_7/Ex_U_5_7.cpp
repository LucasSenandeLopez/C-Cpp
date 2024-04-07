/*

    We are porposed to write a program that displays how many of three students got a grade
    between 8 and 10 while only using three variables

*/
#include <iostream>

using namespace std;

int main()
{
    float grade;
    float avg;
    unsigned int counter;

    counter = 0U;
    avg = 0.0f;


    cout << "Input the first student's lab grade: \n";
    cin >> grade;
    avg += grade * 0.3f;

    cout << "Input the first student's theory grade: \n";
    cin >> grade;
    avg += grade * 0.7f;

    counter = ((int(avg) >= 8) ? counter + 1 : counter);
    avg = 0.0f;



    cout << "Input the second student's lab grade: \n";
    cin >> grade;
    avg += grade * 0.3f;

    cout << "Input the second student's theory grade: \n";
    cin >> grade;
    avg += grade * 0.7f;

    counter = ((int(avg) >= 8) ? counter + 1 : counter);
    avg = 0.0f;



    cout << "Input the third student's lab grade: \n";
    cin >> grade;
    avg += grade * 0.3f;

    cout << "Input the third student's theory grade: \n";
    cin >> grade;
    avg += grade * 0.7f;

    counter = ((int(avg) >= 8) ? counter + 1 : counter);
    avg = 0.0f;



    cout << "Nº of students with more than an 8: " << counter << " \n";
    return 0;
}
