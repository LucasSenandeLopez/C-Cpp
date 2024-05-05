/*
    We are proposed to select a data type, input a value and then show it using a union
*/
#include <iostream>

union Selected_Type
{
    char u_char;
    int u_int;
    float u_float;
    double u_double;

};

struct Var_Type
{
    int type;
    Selected_Type st;
};

void display_type(Var_Type *v_type);

//using namespace std
using std::cout;
using std::cin;

int main()
{
    int type_selection;
    Var_Type type_data;

    do
    {
        cout << "Input a number to select a data type: \n" <<\
            "1 -> char \n" <<\
            "2 -> int \n" <<\
            "3 -> float \n" <<\
            "4 -> double \n";

        cin >> type_selection;

    } while (type_selection > 4 || type_selection < 1);
    
    type_data.type = type_selection;

    display_type(&type_data);
    return 0;
}

void display_type(Var_Type *v_type)
{

    switch (v_type -> type)
    {
    case 1:
        cout << "Introduce a character: \n";
        cin >> v_type -> st.u_char;

        cout << "The value you inputted is: " << v_type -> st.u_char << "\n";
        break;
    
    case 2:
        cout << "Introduce an integer: \n";
        cin >> v_type -> st.u_int;

        cout << "The value you inputted is: " << v_type -> st.u_int << "\n";
        break;
    case 3:
        cout << "Introduce a float: \n";
        cin >> v_type -> st.u_float;

        cout << "The value you inputted is: " << v_type -> st.u_float << "\n";
        break;
    case 4:
        cout << "Introduce a double: \n";
        cin >> v_type -> st.u_double;

        cout << "The value you inputted is: " << v_type -> st.u_double << "\n";
        break;
    }

}