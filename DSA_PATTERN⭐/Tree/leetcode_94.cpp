// Binary Tree Inorder Traversal
/*
   _____                                 
  / ___/____  __  ______ ___  ___  ____  
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \ 
 ___/ / /_/ / /_/ / / / / / /  __/ / / / 
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/  
                                         
*/
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int>inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    for (int value : result) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}