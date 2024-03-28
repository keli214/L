#include <stack>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr) {}
        TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
        TreeNode(int _val, TreeNode *_l, TreeNode * _r): val(_val), left(_l), right(_r) {}

};

TreeNode* deleteNode(TreeNode* root, int key) {
TreeNode *curr = root, *prev = root;
    while(curr && curr->val != key){
        prev = curr;
        if(key > curr->val){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    //if curr is null, we didn't find the node with key
    if(!curr){
        return root;
    }
    //if we find the node
    //if it has both child
    if(curr->left && curr->right){
        //find the inorder successor
        TreeNode* succ = curr->right, *prev = curr;
        while(succ->left){
            prev = succ;
            succ = succ->left;
        }
        curr->val = succ->val;
        if(prev == curr){
            prev->right = succ->right;
        }
        else{
            prev->left = succ->right;
        }
        delete succ;
    }
    //if it has a single child
    else if(curr->left || curr->right){
        TreeNode* child = curr->left ? curr->left : curr->right;
        curr->val = child->val;
        curr->left = child->left;
        curr->right = child->right;
        delete child;
    }
    //leaf node
    else{
        if(prev->left && prev->left->val == key){
            prev->left = nullptr;
            delete curr;
        }
        else if(prev->right && prev->right->val == key){
            prev->right = nullptr;
            delete curr;
        }
        else{//single node with target val
            return nullptr;
        }
    }
    return root;
}