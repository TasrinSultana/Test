//https://leetcode.com/problems/binary-tree-right-side-view/submissions/1009247663/
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

 //apna college 100
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>view;
        if(root==NULL){
            return view;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz_this_level = q.size();
            for(int i = 1; i <= sz_this_level; i++){
                TreeNode* frnt = q.front();
                q.pop();
                if(i == sz_this_level){
                    view.push_back(frnt->val);
                }
                if(frnt->left){
                    q.push(frnt->left);
                }
                if(frnt->right){
                    q.push(frnt->right);
                }
            }
        }
        return view;
    }
};