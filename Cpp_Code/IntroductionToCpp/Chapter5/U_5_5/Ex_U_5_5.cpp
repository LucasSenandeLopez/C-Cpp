/*

    We have to display a message given a student's grade

*/
#include <iostream>

using namespace std;

int main()
{

    unsigned int grade;
    cout << "Introduce your grade: \n";
    cin >> grade;

    grade = ((grade > 20) ? 20 : grade);

    if (grade < 10)
    {
        cout << "Need help \n";

    } else if (grade <= 13){

        cout << "Dangerous Zone \n";

    } else if (grade <= 16) {

        cout << "Good \n";
    } else if (grade <= 18){

        cout << "Very good! \n";

    } else {

        cout << "Excellent! \n";
    } 

    return 0;
}
