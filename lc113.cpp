#include <vector>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//using dfs to find all the root-leaf path and check if the sum equals to target
void dfs(vector<vector<int>>& res, vector<int>& curr, TreeNode* root, int targetSum, int currSum){
    currSum += root->val;
    curr.push_back(root->val);
    if(!root->left && !root->right){
        if(currSum == targetSum){
            res.push_back(curr);
        }
    }
    if(root->left) dfs(res, curr, root->left, targetSum, currSum);
    if(root->right) dfs(res, curr, root->right, targetSum, currSum);
    curr.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> curr;
    vector<vector<int>> res;
    dfs(res, curr, root, targetSum, 0);
}   