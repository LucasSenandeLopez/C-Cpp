/*
    We are proposed to read two files and append the contents of the second file into the first one
*/
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::ios_base;

int main()
{
    string name_file_1("/home/fedesuarez/Documents/CppFiles/");
    string name_file_2("/home/fedesuarez/Documents/CppFiles/");

    string tmp;

    char read_write;

    cout << "Enter file 1: \n";
    std::getline(cin, tmp);
    name_file_1 += tmp;

    tmp = "";

    cout << "Enter file 2: \n";
    std::getline(cin, tmp);
    name_file_2 += tmp;

    std::fstream fst_1(name_file_1.c_str(), ios_base::in | ios_base::out | ios_base::app);
    if (fst_1.is_open() == false)
    {
        std::cerr << "There has been an error opening file 1 with filepath \"" << name_file_1 <<\
            "\"\n";
        exit(EXIT_FAILURE);
    }

    ifstream fst_2(name_file_2.c_str(), ios_base::in);
    if (fst_2.is_open() == false)
    {
        std::cerr << "There has been an error opening file 2 with filepath \"" << name_file_2 <<\
            "\"\n";
        exit(EXIT_FAILURE);
    }

    do
    {
        fst_2 >> read_write;
        fst_1 << read_write;

    } while (fst_2);

    fst_2.close();

    fst_1.seekg(0);

    do
    {
        fst_1 >> read_write;
        cout << read_write;

    } while (fst_1);
    
    cout << "\n";
    return 0;
}
