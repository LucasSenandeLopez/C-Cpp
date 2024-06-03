#include <iostream>
#include <fstream>


using std::cout;
using std::cin;
using std::ifstream;
using std::ios_base;

int main()
{
    float num_file_1;
    float num_file_2;

    ifstream fin_1("/home/fedesuarez/Documents/CppFiles/ex_1.txt", ios_base::in);
    ifstream fin_2("/home/fedesuarez/Documents/CppFiles/ex_2.txt", ios_base::in);

    if(fin_1.is_open() == false)
    {
        std::cerr << "An error has occurred while opening file 1\n";
        exit(EXIT_FAILURE);
    }

    if(fin_2.is_open() == false)
    {
        std::cerr << "An error has occurred while opening file 2\n";
        exit(EXIT_FAILURE);
    }

    do
    {
        fin_1 >> num_file_1;
        fin_2 >> num_file_2;

        if (!(fin_1 && fin_2)){break;}

        if (num_file_1 != num_file_2)
        {
            cout << "The files have different contents\n";
            return 0;
        } 

    } while (1);
    
    if (fin_1)
    {
        cout << "File 1 has more contents\n";
    
    } else if (fin_2) {

        cout << "File 2 has more contents\n";

    } else {

        cout << "Both files have the same contents\n";
    }

    return 0;
}