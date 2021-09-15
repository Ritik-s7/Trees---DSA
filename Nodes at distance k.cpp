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

void distanceK(Node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
        cout << root->value << " ";

    else
    {
        distanceK(root->left, k - 1);
        distanceK(root->right, k - 1);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    distanceK(root, 2);
    return 0;
}