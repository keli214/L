#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* n) : val(x), next(n){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    /* If there are only 1 node left in the list
        return TreeNode(node->val) 
    */
    if(!head)
        return nullptr;
    if(!head->next)
        return new TreeNode(head->val);
    ListNode *fast = head, *slow = head, *last;
    while(fast && fast->next){
        fast = fast->next->next;
        last = slow;
        slow = slow->next;
    }
    last->next = nullptr;
    TreeNode* t = new TreeNode(slow->val);
    t->right = sortedListToBST(slow->next);
    t->left = sortedListToBST(head);
    return t;
}
