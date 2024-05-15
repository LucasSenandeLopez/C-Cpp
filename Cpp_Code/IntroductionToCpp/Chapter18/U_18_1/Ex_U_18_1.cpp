/*
    We are proposed to overload the ostream class so that the main function: 
    
    int main()
    {
    "Show\n" << cout;
    return 0;
    }
    
    is unchanged, compiles and shows:
    "Begin"
    "Show"
    "End"
*/
#include <iostream>
#include <cstring>

using namespace std;


void operator<<(const char * str, ostream& out)
{
    if (!strncmp(str, "Show\n", 5))
    {
        out << "Begin\n" << "Show\n" << "End\n";
    }
    return;
}


int main()
{
    "Show\n" << cout;
    return 0;
}
