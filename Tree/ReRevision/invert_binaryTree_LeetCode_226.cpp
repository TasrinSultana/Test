/*
https://leetcode.com/problems/invert-binary-tree/submissions/1025427799/
https://leetcode.com/problems/invert-binary-tree/submissions/904091567/

1. valo kore kheal korle bujha jabe je root e jaye prothome left right exchange hosse,
tarpor abar tara root hishebe call hosse --- agerbar eivabe korsilam 

2. root e jeye prothome left right ke invert korar jonno recursive call kora hosse, 
tarpor inverted left ar exchange korsi
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};