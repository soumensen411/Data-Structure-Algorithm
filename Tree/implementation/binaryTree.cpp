#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// build tree
static int index = -1;
Node *buildTree(vector<int> &preorder)
{
    index++;
    if (preorder[index] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// pre order Traversal
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// In order Traversal
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// post order Traversal
void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// level order Traversal
void levelOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
    }
}
// {1, 2, 3, 4, 7};
// {1, 2, -1, -1, 3, 4, -1, -1, 7, -1, -1};
void levelOrderTraversalWithNewlines(Node *root)
{
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if (current == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

void treeOperations()
{
    vector<int> preorder = {
        50, 30, 20, -1, -1, 40, 35, -1, -1, 45, -1, -1,
        70, 60, -1, 65, -1, -1, 80, -1, 90, -1, -1};

    Node *root = buildTree(preorder);
    cout << "\nTraversal Tree in PreOrder sequence\n";
    cout << "------------------------------------\n";
    preorderTraversal(root);
    cout << endl;

    cout << "\n\nTraversal Tree in InOrder sequence\n";
    cout << "------------------------------------\n";
    inorderTraversal(root);
    cout << endl;

    cout << "\n\nTraversal Tree in PostOrder sequence\n";
    cout << "------------------------------------\n";
    postorderTraversal(root);
    cout << endl;

    cout << "\n\nTraversal Tree in LevelOrder sequence\n";
    cout << "------------------------------------\n";
    levelOrderTraversal(root);
    cout << endl;

    cout << "\n\nTraversal Tree in LevelOrder with new line sequence\n";
    cout << "------------------------------------\n";
    levelOrderTraversalWithNewlines(root);
    cout << endl;
}
int main()
{
    freopen("output.txt", "w", stdout);
    treeOperations();
    return 0;
}