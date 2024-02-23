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
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        //check the node if it's in place
        if(!first && prev && prev->val > root->val)
            first = prev;
        if(prev->val && prev->val > root->val)  
            second = root;    
        prev = root;
        inorder(root->right);
    }
public:
    /* Using inorder traversal to find the two elements that are out of order
    Since inorder traversal returns an sorted ascending values, if there are two
    nodes out of place, there must be a larger node in a place that is before its
    original place and a smaller node in a place that is after its correct place.
    So the first node will be the prev node at the first time we encounter 
    a node < prev, and the second node will be the node < prev at the second time.  */
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

