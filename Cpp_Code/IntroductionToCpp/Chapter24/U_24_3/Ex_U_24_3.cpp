/*
    We are proposed to create a program that checks for the sequential doubled words
    e.g: In "THIS THIS" chapter we present... and write them in another file
*/
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios_base;

int main()
{
    string str1("");
    string temp("");


    ifstream fin("/home/fedesuarez/Documents/CppFiles/ex_3_1.txt", ios_base::in);
    if (fin.is_open() == false)
    {
        std::cerr << "An error has occured while opening the input file" << std::endl;
        exit(EXIT_FAILURE);
    }

    ofstream fout("/home/fedesuarez/Documents/CppFiles/ex_3_2.txt", ios_base::out | ios_base::trunc);
    if (fout.is_open() == false)
    {
        std::cerr << "An error has occured while opening the output file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (fin)
    {
        fin >> str1;

        if (str1 == temp)
        {
            cout << "Sending \"" << str1 << "\" to output file\n";
            fout << str1 << " ";
        }

        temp = str1;
    }

    return 0;
}
