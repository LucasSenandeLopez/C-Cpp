/*
    We are proposed to read the number of passing and failing students in a txt file
*/
#include <iostream>
#include <fstream>
#include <iomanip>

//using namespace std
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios_base;
using std::string;

int main()
{
    float grd;
    int passed = 0;
    int failed = 0;
    float sum_passed = 0.0f;
    float sum_failed = 0.0f;


    //string str;

    /*
    We had to create a file first

    int flag = 1;

    ofstream fout("/home/fedesuarez/Documents/CppFiles/ex_1.txt",\
        ios_base::out | ios_base::app);

    if(fout.is_open() == false)
    {
        std::cerr << "An error has occurred\n";
        exit(EXIT_FAILURE);
    }
    while(flag)
    {
        do
        {
            cout << "Enter a grade from 1 to 10\n";
            cin >> grd;
        } while (grd < 0.0f || grd > 10.0f);

        fout << std::fixed << std::setprecision(2) << grd << "\n";    
        
        cout << "If you don't want to keep inserting numbers, type 0\n";
        cin >> flag;
    }
    fout.close();
    */

    ifstream fin("/home/fedesuarez/Documents/CppFiles/ex_1.txt", ios_base::in);

    if(fin.is_open() == false)
    {
        std::cerr << "An error has occurred\n";
        exit(EXIT_FAILURE);
    }


    while (fin)
    {
        fin >> grd;
        if (grd < 5.0f)
        {
            sum_failed += grd;
            ++failed;
        } else {

            sum_passed += grd;
            ++passed;
        }
    }

    if(!fin.eof())
    {
        std::cerr << "An error has occurred\n";
        exit(EXIT_FAILURE);
    }

    cout << "There were " << passed + failed << " students; " << passed << " passed and " << failed\
        << " failed.\nThe average passing grade is " << sum_passed/float(passed) <<\
        " and the average failing grade is " << sum_failed/float(failed) << "\n";    
    return 0;
}
