struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    Remove all the leaf node with the target value and the nodes that becomes leaf node 
    after such removal. 
    using dfs to find the leaf node with target value, if a leaf node if find( root->left and root->right are both null),
    check if the curr node has the target value return nullptr if so 
*/
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(!root){
        return nullptr;
    }
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(root->val == target && !root->left && !root->right)
        return nullptr;
    return root;
}