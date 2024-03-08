#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            for(int i = 0; i < l; i++){
                Node* prev = q.front();
                q.pop();
                prev->next = i == l-1 ? nullptr: q.front();
                if(prev->left) q.push(prev->left);
                if(prev->right) q.push(prev->right);
            }
        }
        return root;
    }
};