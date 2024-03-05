#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};
/*
    Build the left and right sub tree with each num i ~ (start, end) as root
    construct the tree by storing those sub tree in the left and right lists

*/
vector<TreeNode*> buildTrees(int start, int end){
    if(start > end){
        return {nullptr};
    }
    vector<TreeNode*> res;
    for(int i = start; i <= end; i++){
        vector<TreeNode*> left = buildTrees(start, i-1);
        vector<TreeNode*> right = buildTrees(i+1, end);

        //combine each left sub tree with all right sub tree to get all possible combinations
        for(int j = 0; j < left.size(); j++){
            for(int k = 0; k < right.size(); k++){
                TreeNode* curr = new TreeNode(i);
                curr->left = left[j];
                curr->right = right[k];
                res.push_back(curr);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    return buildTrees(1,n);
}