struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
/*
    remove a given node in a linked list
    all node values are unique in the node
    swap the current node with the next node
    until we reach the last node 
    remove the last node by setting the prev->next to nullptr
*/

void deleteNode(ListNode* node) {
    ListNode* curr = node->next, *prev = node;
    while(curr){
        int temp = node->val;
        node->val = curr->val;
        curr->val = temp;
        prev = node;
        curr = curr->next;
        node = node->next;
    }
    prev->next = nullptr;
}
