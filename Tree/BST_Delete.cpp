// https://leetcode.com/problems/delete-node-in-a-bst/submissions/
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

 // apna college 108 er video theke shikhesi
 // 3 ta case hote pare 
 // oi node er kono child na thaka, eitai temon jhamela nai
 // jekono ekta child thakle tar oi child takei oi node hishebe return kore oi node ta delete kore dite hobe
 // uporer 2ta case e if & else if solve hoye jai
 // problem holo jodi left right 2tai thake tokhon oi delete korle er immidate boro je man tree te
 // ase take eikhane niye asha uchit and oi immidate boro tar node delete kora uchit.
 // immidate boro holo er ekbar dan dike jeye bam e jete thaka, mane ektu boror dike jeye joto para
 // jai sotor dike jete hobe eitake inorderSuccessor bole eitar jonno alada function baniye node ta return kori
 // tobe inorder successor delete korte hole er ager tar pointer change korte hobe onno case gulote
 // easily recursive way te hoye jasse kintu eikhane to inorderSuccessor er node na borong changed root
 // ke return korte hobe
 // so inorderSuccessor ke abar same way te recursive call korte hobe, eibar ekbarei hoye jabe karon
 // eibar hoy left right keu nai, nahoy shudhu right ase, tobe eikhane root hishebe shuru korte hobe
 // eikhaner root er right diye nahole parent er access paoa jasse na tai control kora jasse na
class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root){
        root = root->right;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
            if(root->left == NULL){
                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            }
            else if(root->right == NULL){
                TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
            }
            // eikhane asha manei left o ase right o ase
            TreeNode* inorderS = inorderSuccessor(root);
            root->val = inorderS->val;
            root->right = deleteNode(root->right, inorderS->val);
        }
        return root;
    }
};