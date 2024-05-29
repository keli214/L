#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};
bool dfs(TreeNode* root, int limit, int currSum){
    currSum += root->val;
    bool left = false, right = false;
    if(root->left) left = dfs(root->left, limit, currSum);
    if(root->right) right = dfs(root->right, limit, currSum);
    if(!left && !right){
        return currSum >= limit;
    }else if(!left){
        root->left = nullptr;
    }else if(!right){
        root->right = nullptr;
    }
    return true;
}
TreeNode* sufficientSubset(TreeNode* root, int limit) {
    bool hasRoot = dfs(root, limit, 0);
    if(!hasRoot){
        return nullptr;
    }
    return root;
}

void printTree(TreeNode* root){
    if(!root){
        std::cout<<" null ";
        return;
    }
    std::cout<<" "<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    TreeNode* node1 = new TreeNode(-5);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(2, node1, nullptr);
    TreeNode* node4 = new TreeNode(-3, node2, nullptr);
    TreeNode* node5 = new TreeNode(1, node3, node4);
    auto res = sufficientSubset(node5, -1);
    printTree(res);
    bool test;
    std::cout<<test;
}