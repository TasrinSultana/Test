
/*
er agerbar voyanok soln korsilam, eibarer ta simple
https://leetcode.com/problems/path-sum/submissions/1025389785/
if the tree has a root-to-leaf path such that adding up all the 
values along the path equals targetSum.

clear na hole D:\CPP\Tree\ReRevision\minimum_depth_BT.cpp eita dekhte hobe 
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

//
class Solution {
public:
    bool ck = 0;
    void pathSum(TreeNode* root, int targetSum, int sum_now){
        if(root==NULL) return;
        sum_now += root->val;
        if(root->left==NULL && root->right==NULL && sum_now == targetSum){
            ck = 1;
            return;
        }
        pathSum(root->left, targetSum, sum_now);
        pathSum(root->right, targetSum, sum_now);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        pathSum(root, targetSum, 0);
        return ck;
    }
};