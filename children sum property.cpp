#include <iostream>
#include <queue>
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

bool children(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left != NULL)
        sum = sum + root->left->value;

    if (root->right != NULL)
        sum = sum + root->right->value;

    return (sum == root->value && children(root->left) && children(root->right));
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(60);
    root->left->right = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << children(root);
    return 0;
}