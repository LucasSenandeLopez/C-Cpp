/*
    We are proposed to read data from a binary file, sort it and send it to
    another binary file
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>


using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::ios_base;


int main()
{
    float grd = 0.0f;
    vector<float> grades;

    // To initialize the binary file

    ofstream fout("/home/fedesuarez/Documents/CppFiles/ex_11_in.bin",\
        ios_base::out | ios_base::trunc);

    if (fout.is_open() == false)
    {
        std::cerr << "An error has occurred\n";
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        do
        {
            cout << "Enter a grade from 0 to 10 or negative to stop inserting\n";
            cin >> grd;

        } while (grd > 10.0f);

        if (grd <= -0.00001f) {break;}

        fout << std::fixed << std::setprecision(2) << grd << "\n";    
        
    }

    fout.close();
    cout << "Insertion ended" << std::endl;


    ifstream fin("/home/fedesuarez/Documents/CppFiles/ex_11_in.bin", ios_base::in);
    if (fin.is_open() == false)
    {
        std::cerr << "An error has occurred\n";
        exit(EXIT_FAILURE);
    }

    while (fin)
    {
        fin >> grd;
        grades.push_back(grd);
    }

    fin.close();
    sort(grades.begin(), grades.end());

    fout.open("/home/fedesuarez/Documents/CppFiles/ex_11_sort.txt",\
        ios_base::out | ios_base::trunc);


    for (float& element : grades)
    {
        fout << element << " ";
    }
    fout.close();
    return 0;
}
