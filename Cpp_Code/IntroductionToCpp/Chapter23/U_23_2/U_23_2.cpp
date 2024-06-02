/*
    We are proposed to recreate a Stack data structure using templates
*/
#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::cin;
using std::string;
using std::endl;

template <typename T> class Stack;

template <typename T> class Node
{
private:
    string name;
    T data_1;
    T data_2;
    Node *next;
public:
    Node(const string& init_name, T init_d1, T init_d2) : name(init_name),\
        data_1(init_d1), data_2(init_d2) {next = nullptr;}

    template <typename V> friend ostream& operator<<(ostream& out, Node<V>& nd);
    friend class Stack<T>;
};

template <typename V> ostream& operator<<(ostream& out, Node<V>& nd)
{
    out << nd.name << " " << nd.data_1 << " " << nd.data_2 << "\n";
    return out;
}


template <typename T> class Stack
{
private:
    Node<T> *head;
    int members;
    void recpop(Node<T>*& nd);
    void recshow(Node<T>*& nd);

public:
    Stack()
    {
        head = nullptr;
        members = 0;
    }
    void add_stack(Node<T> nd);
    void show_stack();
    void pop();
    bool operator==(Stack<T> st);
};

template <typename T> void Stack<T>::recpop(Node<T>*& nd)
{
    if (nd == nullptr)
    {
        cout << "The stack is empty\n" << endl;
        return;

    } else if (nd->next == nullptr)
    {
        cout << *nd << endl;
        delete nd;
        nd = nullptr;
        --members;
        return;
        
    }
    recpop(nd->next);
}

template <typename T> void Stack<T>::recshow(Node<T>*& nd)
{
    if (nd == nullptr)
    {
        return;

    }
    recshow(nd->next);
    cout << *nd;
}


template <typename T> void Stack<T>::add_stack(Node<T> nd)
{
    if (head == nullptr)
    {
        head = new Node<T>(nd.name, nd.data_1, nd.data_2);
        ++members;
        return;
    }

    Node<T>* orig_address = head;

    while ((head->next) != nullptr)
    {
        head = head->next;
    };

    head -> next = new Node<T>(nd.name, nd.data_1, nd.data_2);
    ++members;

    head = orig_address;
}

template <typename T> void Stack<T>::show_stack()
{
    recshow(head);
    cout << endl;
}

template <typename T> void Stack<T>::pop()
{
   recpop(head);
}

template <typename T> bool Stack<T>::operator==(Stack<T> st)
{
    if (members != st.members){return false;}
    Node<T> *tmp = head;
    
    for(int i = 0; i < members; ++i)
    {
        if (tmp->name != st.head->name) {return false;}

        st.head = st.head->next;
        tmp = tmp->next;
    }
    return true;
}



int main()
{

    Node n1("First", 1, 2), n2("Sec", 3, 4), n3("Third", 5, 6);
    Stack<int> st1;

    st1.add_stack(n1);
    st1.add_stack(n2);
    st1.add_stack(n3);

    st1.show_stack();

    st1.pop();

    st1.show_stack();

    Stack<int> st2;
    st2.add_stack(n1);
    st2.add_stack(n2);

    cout << ((st1 == st2) ? "Same\n" : "Different\n");

    return 0;
}
