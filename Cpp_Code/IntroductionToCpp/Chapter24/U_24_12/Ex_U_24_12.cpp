/*
    We are proposed to implement the Caesar encryption algorithm
*/
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios_base;

int main()
{

    int option;
    long unsigned int length = 0;
    long unsigned int counter = 0;
    string filename("/home/fedesuarez/Documents/CppFiles/");
    string tmp;
    string tmp_name;
    char *text;

    cout << "Enter file name" << std::endl;
    std::getline(cin, tmp_name);

    filename += tmp_name;

    ifstream fin;
    ofstream fout;

while(1)
{

    do
    {
        cout << "Choose one:\n1: Encrypt a file.\n2: Decrypt a file.\n3: Terminate." << std::endl;
        cin >> option;

    } while (option < 1 || option > 3);
    
    cout << "\n\n";

    switch (option)
    {
    case 1:

        fin.open(filename.c_str(), ios_base::in);
        if (fin.is_open() == false)
        {
            std::cerr << "An error has occurred while opening the file\n";
            exit(EXIT_FAILURE);
        }
        while (fin)
        {
            std::getline(fin, tmp);

            for (long unsigned int i = 1; i <= tmp.length(); ++i)
            {
                ++length;
                
            }
            ++length;
        }
        --length; 
        fin.clear();
        fin.seekg(0, ios_base::beg);

        text = new char[length];

        while (fin)
        {

            std::getline(fin, tmp);
            
            for (long unsigned int i = 0; i != tmp.length(); ++i)
            {

                if ((tmp[i] >= 'A' && tmp[i] <= 'W') || (tmp[i] >= 'a' && tmp[i] <= 'w'))
                {
                    tmp[i] += 3;

                } else if ((tmp[i] >= 'X' && tmp[i] <= 'Z') || (tmp[i] >= 'x' && tmp[i] <= 'z')){

                    tmp[i] -= 23;
                }

                text[counter++] = tmp[i];
            }

            text[counter++] = '\n';
            
        }
        text[length - 1] = '\n';        
        
        cout << "Length: " << length  << std::endl;

        fin.clear();
        fin.close();
        
        fout.open(filename.c_str(), ios_base::out | ios_base::trunc);
        if (fout.is_open() == false)
        {
            std::cerr << "An error has occurred while opening the file\n";
            exit(EXIT_FAILURE);
        }

        fout.seekp(0, ios_base::beg);

        for (long unsigned int i = 0; i != length; ++i)
        {
            fout << text[i];
        }
        fout.clear();
        fout.close();

        cout << "The file \"" << tmp_name << "\" with length " << length << " characters "<<\
            "has been encrypted" << std::endl;

        delete[] text;
        length = 0;
        counter = 0;
        break;
    
    case 2:
        fin.open(filename.c_str(), ios_base::in);
        if (fin.is_open() == false)
        {
            std::cerr << "An error has occurred while opening the file\n";
            exit(EXIT_FAILURE);
        }


        while (fin)
        {
            std::getline(fin, tmp);

            for (long unsigned int i = 1; i <= tmp.length(); ++i)
            {
                ++length;
                
            }
            ++length;
        }
        --length; 
        fin.clear();
        fin.seekg(0, ios_base::beg);

        text = new char[length];

        while (fin)
        {
            std::getline(fin, tmp);
            
            for (long unsigned int i = 0; i != tmp.length(); ++i)
            {

                if ((tmp[i] >= 'D' && tmp[i] <= 'Z') || (tmp[i] >= 'd' && tmp[i] <= 'z'))
                {
                    tmp[i] -= 3;

                } else if ((tmp[i] >= 'A' && tmp[i] <= 'C') || (tmp[i] >= 'a' && tmp[i] <= 'c')){

                    tmp[i] += 23;
                }

                text[counter++] = tmp[i];
            }

            text[counter++] = '\n';
            
        }
        text[length - 1] = '\n';        

        fin.clear();
        fin.close();
        
        fout.open(filename.c_str(), ios_base::out | ios_base::trunc);
        if (fout.is_open() == false)
        {
            std::cerr << "An error has occurred while opening the file\n";
            exit(EXIT_FAILURE);
        }

        fout.seekp(0, ios_base::beg);

        for (long unsigned int i = 0; i != length; ++i)
        {
            fout << text[i];
        }
        fout.clear();
        fout.close();

        cout << "The file \"" << tmp_name << "\" with length " << length << " characters "<<\
            "has been decrypted" << std::endl;

        delete[] text;
        length = 0;
        counter = 0;
        break;

    case 3:
        cout << "Ending program\nResulting text: \n";

        fin.open(filename.c_str(), ios_base::in);
        if (fin.is_open() == false)
        {
            std::cerr << "An error has occurred while opening the file\n";
            exit(EXIT_FAILURE);
        }


        while(fin)
        {
            std::getline(fin, tmp);
            cout << tmp << "\n";
        }




        return 0;
    }
}
}

