struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};
/*
    using DFS to find the evaluation of the tree
*/
bool evaluateTree(TreeNode* root) {
    if(root->val == 0) 
        return false;
    else if(root->val == 1)
        return true;
    else if(root->val == 2)
        return evaluateTree(root->left) && evaluateTree(root->right);
    else //3
        return evaluateTree(root->left) || evaluateTree(root->right);
}