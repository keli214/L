
 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    check if tree1 is the flip version of tree2
    where there can be any number of swap of subtress

*/
 bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 && root2) return false;
        if(root1 && !root2) return false;
        if(root1 && root2 && root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) 
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)); 
    }