//https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1009456518/

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
 // apna college 108
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return root;
        }
        if(root->val == val){
            return root;
        }
        else if(val > root->val){
            TreeNode* tmp = searchBST(root->right, val);
            return tmp;;
        }
        else{
            TreeNode* tmp = searchBST(root->left, val);
            return tmp;
        }
    }
};