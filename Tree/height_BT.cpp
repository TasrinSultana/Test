// https://leetcode.com/problems/diameter-of-binary-tree/

//O(n^2) soln-- apna college 97

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

int calc_height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(calc_height(root->left), calc_height(root->right))+1;
}



    /*
                1        ---- 3 height
          2           3     -- 2 height

        4    5      6    7     -- 1 height
    */