//judged https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// apna college 102(Shortest Distance between 2 Nodes){videor system valo lageni, LCA ber kore,
// LCA ar node 2tar level ber kore (level(LCA-1tanode)+level(LCA-arekta node)
// tobe level e root theke shuru korte hobe, nich theke height calculate korle hobe na-
class Solution{
    public:
    int level_ck;
    Node* find_lca(Node* root, int n1, int n2){//RETURN TYPE Node* rekhe korte hobe
        if(root==NULL){
            return NULL;
        }
        if(root->data == n1 || root->data == n2){
            return root;
        }
        Node* l = find_lca(root->left, n1, n2);
        Node* r = find_lca(root->right, n1, n2);
    
        if(l && r){
            return root;
        }
        else if(l){
            return l;
        }
        return r;
    }
    void find_level(Node* root, int n, int level){
        if(root==NULL) return;
        if(root->data==n){
            level_ck = level;
            return;
        }
        find_level(root->left, n, level + 1);
        find_level(root->right, n, level + 1);
    }
    int findDist(Node* root, int a, int b) {
        Node* lca =  find_lca(root, a, b);
        find_level(root, lca->data, 1);
        int level_lca = level_ck;
        find_level(root, a, 1);
        int level_a = level_ck;
        find_level(root, b, 1);
        int level_b = level_ck;
        return (level_a + level_b - 2* level_lca);
    }
};