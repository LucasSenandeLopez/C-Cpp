/*
    We are proposed to write a function that creates nodes in a Binary Search Tree
    without using recursion
*/
#include <iostream>

using std::cout;
using std::cin;

struct BST_Node
{
    int key;
    BST_Node* left;
    BST_Node* right;
};

void insert_node(BST_Node* root, int new_key);

int main()
{
    BST_Node root = {};
    int key;

    do
    {
        cout << "Insert a key or 0 to terminate the loop: \n";
        cin >> key;

        if(!key){return 0;}

        insert_node(&root, key);

    } while (1);
    

    return 0;
}

void insert_node(BST_Node *root, int new_key)
{

    if (!(root -> key))
    {
        cout << "Initializing BST with value " << new_key << " \n";
        root -> key = new_key;
        return;
    }

    cout << root -> key << " -> ";

    do
    {
        if (new_key > (root -> key))
        {

            if ((root -> right) == nullptr)
            {
                root -> right = new BST_Node;
                root = root -> right;

                root -> key = new_key;
                root -> left = nullptr;
                root -> right =  nullptr;
                
                cout << new_key << "\n";

                return;
            }

            root = root -> right;
            cout << root -> key << " -> ";

        } else if (new_key < (root -> key)) {

            if ((root -> left) == nullptr)
            {
                root -> left = new BST_Node;
                root = root -> left;

                root -> key = new_key;
                root -> left = nullptr;
                root -> right =  nullptr;
                
                cout << new_key << "\n";

                return;
            }

            root = root -> left;
            cout << root -> key << " -> ";

        } else {
            
            cout << new_key << "\n";
            return;
        }

    } while (1);
    
}