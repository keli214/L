#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode () : val(0), left(nullptr), right(nullptr) {}
    TreeNode (int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode (int _val, TreeNode *leftChild, TreeNode *rightChild) : 
        val(_val), 
        left(leftChild), 
        right(rightChild) {}
};

class Solution {
private:

    void morris(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        while(root){
            if(!root->left){
                res.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* prev = root;
                root = root->left;
                while(root->right && root->right != prev){
                    root = root->right;
                }
                if(!root->right){
                    res.push_back(prev->val);
                    root->right = prev;
                    root = prev->left;
                }
                else{
                    root->right = nullptr;
                    root = prev->right;
                }
            }
        }
    }
public:
    vector<int> recoverTree(TreeNode* root) {
        vector<int> res;
        morris(root, res);
        return res;
    }
};
