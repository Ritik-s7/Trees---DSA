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

// Iterative solution

void LeftView2(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->value << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
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

    LeftView2(root);
    return 0;
}