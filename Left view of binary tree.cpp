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

int maxlevel = 0;
void LeftView(Node *root, int level)
{

    if (root == NULL)
    {
        return;
    }

    if (level > maxlevel)
    {
        cout << root->value << " ";
        maxlevel = level;
    }
    LeftView(root->left, level + 1);
    LeftView(root->right, level + 1);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    LeftView(root, 1);
    return 0;
}