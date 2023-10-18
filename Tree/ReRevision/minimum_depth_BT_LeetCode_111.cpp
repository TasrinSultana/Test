//https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/1025371236/
/*height er function e max er jaigai min dile hobe na
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5 // ei ta edge case

The minimum depth is the number of nodes along the shortest path from the root node
down to the nearest leaf node.

Input: root = [3,9,20,null,null,15,7]
Output: 2
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
//recursive porer bar eita korsi
class Solution {
public:
    int min_h = 999999;
    void min_height(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){//root theke min dist leaf(kono child nei) node jete hobe 
            min_h = min(min_h, level);
        }
        min_height(root->left, level+1);
        min_height(root->right, level+1);
    }
    int minDepth(TreeNode* root) {
        min_height(root, 1);
        if(min_h == 999999) return 0;
        return min_h;
    }
};

//bfs/ level order style eita agey korsilam
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int level = 1;
        int min_depth = INT_MAX;
        while(!q.empty()){
            TreeNode* nd = q.front();
            q.pop();
            if(nd){
                if(nd->left){ // left jodi thake, na thakle null hobe ja 0 so if true hobena
                    q.push(nd->left);
                }
                if(nd->right){
                    q.push(nd->right);
                }
                
                if(nd->left==NULL && nd->right==NULL){ 
                    min_depth = min(min_depth, level);
                }
            }
            else{
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
            }
        }
        return min_depth;
        
    }
};