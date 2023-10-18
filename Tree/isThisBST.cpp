// https://www.hackerrank.com/challenges/is-binary-search-tree/submissions/code/337467371
// hacker Rank e korsi
// apna college er 110(Check for BST) video kintu ami eita follow korini
// ami sipmle vabe koresi karon BST ke inorder traversal korle always assending sorted array paoa jai
// so inorder traversal e sorted array pelei sure BST (geekForgeeks eu ase)
//https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/?ref=lbp
// eita drawback hosse O(n) space lagte pare amar tai kintu efficient tai extra space lagbe na
// apna college er video and geekForgeeks(amar tau ase) e efficient ta ase
// hackerRank e 0<=data<=10000 bola ase tai ami prev = -1 dhore korte peresi so O(1) space legese shudhu
// technically out of bound dhorle kora jabe O(1) space e
// ar na dhora gele vector ba erokom extra memory te inorder traversal er data gulo store kore then
// check korte hobe sorted kina

//***************************** Need to Revise it frequently


/* Hidden stub code will pass a root argument to the function below. 
Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    int prev = -1;
    bool inOrder(Node* root){
        if(root == NULL){
            return true;
        }
        bool l = inOrder(root->left);
        if(root->data <= prev){
            return false;
        }   
        prev = root->data;
        bool r = inOrder(root->right);
        return l & r;
    }
	bool checkBST(Node* root) {
		return inOrder(root);
	}