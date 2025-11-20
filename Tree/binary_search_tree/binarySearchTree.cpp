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
// ================ TRAVERSAL ================

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << " ";
}

// ================ Delete Node form the bst ================
Node *getInorderSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return NULL;
    }
    if (root->value > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->value < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *inorderSuccessor = getInorderSuccessor(root->right);
            root->value = inorderSuccessor->value;
            root->right = deleteNode(root->right, inorderSuccessor->value);
        }
    }
}

void BSToperations()
{

    vector<int> v = {50, 30, 20, 40, 35, 45, 70, 60, 65, 80, 90};
    Node *root = nullptr;
    // insert data into bst
    for (auto i : v)
    {
        root = buildBinarySerarchTree(root, i);
    }
    // traversal into bst
    cout << "preorder BST Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Inorder BST Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "postorder BST Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // searching value fram a bst
    cout << (search(root, 50) ? "Yes" : "NO") << endl; 
    cout << (search(root, 100) ? "Yes" : "NO") << endl; 

    // delete Node from bst
    deleteNode(root, 35);
    cout << "preorder BST Traversal: ";
    preorderTraversal(root);
    cout << endl;
}

int main()
{
    freopen("output.txt", "w", stdout);
    BSToperations();
}