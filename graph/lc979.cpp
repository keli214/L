#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    Given a binary tree with n nodes such that n coins are distributed 
    among different nodes. Find the min number of move such that each node get 
    one coin exactly

    The number of move = # coins at curr val + # nodes - prev level val
*/
int numMove = 0;

int dfs(TreeNode* root){
    if(!root){
        return 0;
    }
    int l = dfs(root->left);
    int r = dfs(root->right);
    int extra = root->val - 1 + l + r;
    numMove += abs(extra);
    return extra;
}

int distributeCoins(TreeNode* root) {
    dfs(root);
    return numMove;
}

int main(){

}
 