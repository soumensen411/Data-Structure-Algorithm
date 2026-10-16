//  Invert Binary Tree
/*
   _____
  / ___/____  __  ______ ___  ___  ____
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \
 ___/ / /_/ / /_/ / / / / / /  __/ / / /
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/

*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "\n";
}

int main() {
    /*
          4
        /   \
       2     7
      / \   / \
     1   3 6   9
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree (Level Order): ";
    printLevelOrder(root);

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    cout << "Inverted tree (Level Order): ";
    printLevelOrder(invertedRoot);

    return 0;
}