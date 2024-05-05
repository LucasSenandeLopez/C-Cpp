/*
    We are proposed to print the status registry of a printer for 20
    pages using bit fields.
*/
#include <iostream>


struct Print_reg
{
    //Byte 1
    unsigned int page_number : 8;

    //Byte 2
    unsigned int paper_jam : 1;
    unsigned int error_code : 4;
    unsigned int low_ink : 2;
    unsigned int clean : 1;


};


using std::cout;
using std::cin;

int main()
{
    Print_reg page_registry;

    for (unsigned int page = 1; page <= 20; ++page)
    {

        page_registry = {0U, 0U, 0U, 0U, 0U};

        page_registry.page_number = (unsigned char)page;

        if (page >= 9U){page_registry.low_ink = 3U;}

        if (page == 13U){page_registry.error_code = 10U;}

        if (page == 15U){page_registry.paper_jam = 1U;}

        if (page == 20U){page_registry.clean = 1U;}

        cout << "Printing registry of page " << page << ": \n"<< \
            "Paper jam: " << page_registry.paper_jam << " \n"<< \
            "Error code: " << page_registry.error_code << " \n"<< \
            "Low ink: " << page_registry.low_ink << " \n"<< \
            "Clean: " << page_registry.clean << " \n";
    }

    return 0;
}