#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int value;
    Node(int x)
    {
        value = x;
        left = right = NULL;
    }
};

int maximum(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->value, max(maximum(root->left), maximum(root->right)));
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << maximum(root);
    return 0;
}