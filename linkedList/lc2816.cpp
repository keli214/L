#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    reverse the linked list and then 
    double each value + carry 
    reverse the linked list again
    */
ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr, *curr = head;
    while(curr){
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}
ListNode* doubleIt(ListNode* head) {
    ListNode* reversed = reverse(head);
    int carry = 0;
    ListNode* curr = reversed, *prev;
    while(curr){
        int value = curr->val * 2 + carry;
        curr->val = value%10;
        carry = value > 10 ? 1 : 0; 
        prev = curr;
        curr = curr->next;
    }
    if(carry){
        ListNode* carryNode = new ListNode(carry, nullptr);
        prev->next = carryNode;
    }
    reversed = reverse(reversed);
    return reversed;
}

int main(){
    ListNode* n3 = new ListNode(9, nullptr);
    ListNode* n2 = new ListNode(9, n3);
    ListNode* n1 = new ListNode(9, n2);
    ListNode* d =  doubleIt(n1);
    while(d){
        cout<<d->val;
        d = d->next;
    }
}