//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/1009417244/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
 // solution ta height-balanced binary search tree hoyni shudhu BST hoyese
class Solution {
public:
    TreeNode* insert_BST(TreeNode* root, int data){
        if(root==NULL){
            TreeNode* realRoot = new TreeNode(data);
            return realRoot;
        }
        else if(data > root->val){
            root->right = insert_BST(root->right, data);
        }
        else root->left = insert_BST(root->left, data);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        TreeNode* root = NULL;// agei declare na korle return korar jonno paoa jabe na
        // ar NULL vabei define kora lagbe karon insertion shudhu null node ei hoy
        while(head!=NULL){
            root = insert_BST(root, head->val);// eikhane jokhon return hosse tokkhon mul root e return hosse bar bar
            // abar jaoar shomoy o mul root e jasse
            head = head->next;
        }
        return root;
    }
};