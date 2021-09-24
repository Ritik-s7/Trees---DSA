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
// Method 1
int height(Node *root)
{
    if (root == NULL)
        return 0;

    return (max(height(root->left), height(root->right)) + 1);
}

bool balanced(Node *root)

{
    if (root == NULL)
        return true;
    int l = height(root->left);
    int r = height(root->right);

    return (abs(l - r) <= 1 && balanced(root->left) && balanced(root->right));
}

// Efficient Method
int balanced2(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = balanced2(root->left);
    if (lh == -1)
        return -1;

    int rh = balanced2(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    else
    {
        return max(lh, rh) + 1;
    }
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
    root->right->right->right = new Node(50);

    cout << balanced2(root);
    return 0;
}