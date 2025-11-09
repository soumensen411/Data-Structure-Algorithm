#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *buildBinarySerarchTree(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->value)
    {
        root->left = buildBinarySerarchTree(root->left, value);
    }

    else
    {
        root->right = buildBinarySerarchTree(root->right, value);
    }
    return root;
}

// search for a element from a tree
bool search(Node *root, int key)
{
    if (root == nullptr)
        return false;
    if (root->value == key)
    {
        return true;
    }
    if (root->value > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}
int main()
{
    vector<int> v = {50, 30, 20, 40, 35, 45, 70, 60, 65, 80, 90};
    Node *root = nullptr;
    for (auto i : v)
    {
        root = buildBinarySerarchTree(root, i);
    }
    inorderTraversal(root);
    cout << (search(root, 50) ? "Yes" : "NO") << endl;
}