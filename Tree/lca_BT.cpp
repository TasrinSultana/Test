//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // apna college 105
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        if(root == p || root == q){
            return root;
            // ektar niche jodi arekta thake tau eikhanei handle hosse
            //2 ta alada alada jaigai thakleu problem hobe na
        }
        TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);

        if(left_lca && right_lca){
            return root;
        }
        // right theke na paoa mane right to hobei na ei root o hobe na
        else if(left_lca){
            return left_lca;
        }
        return right_lca;
    }
};