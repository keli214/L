
#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    Remove every node which has a node 
    with a greater value anywhere to the right side of it.
    
    keep an decreasing stack 

    [5,2,13,3,8] -> [13, 8]
*/
ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> res;
    res.push(head);
    ListNode* curr = head;
    while(curr){
        while(!res.empty() && curr->val > res.top()->val){
            res.pop();
        }
        res.push(curr);
        curr = curr->next;
    }
    ListNode* dummy = new ListNode(0);
    while(!res.empty()){
        ListNode* tmp = dummy->next;
        curr = res.top();
        res.pop();
        dummy->next = curr;
        curr->next = tmp;
    }
    return dummy->next;
}

int main(){
    ListNode *node1 = new ListNode(8);
    ListNode *node2 = new ListNode(3, node1);
    ListNode *node3 = new ListNode(13, node2);
    ListNode *node4 = new ListNode(2, node3);
    ListNode *node5 = new ListNode(5, node4);
    ListNode* res = removeNodes(node5);
    while(res){
        cout<<res->val;
        res = res->next;
    }
}