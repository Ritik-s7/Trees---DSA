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

// Method 1 ( Naive Approach )
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

void printDistK(Node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->value << " ";
    }

    else
    {
        printDistK(root->left, k - 1);
        printDistK(root->right, k - 1);
    }
}

void LOT(Node *root, int k, int height)
{
    while (k < height)
    {
        printDistK(root, k);
        k++;
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    int h = height(root);
    LOT(root, 0, h);
    return 0;
}