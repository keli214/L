struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* Swapping the node can be done by swapping the value of the listNode*/
ListNode* swapNodes(ListNode* head, int k) {
    ListNode *fir = head;
    ListNode *dummy = new ListNode(0, head);
    for(int i = 1; i < k; i++){
        fir = fir->next;
    }
    ListNode *end = fir->next, *sec = head;
    while(end){
        end = end->next;
        sec = sec->next;
    }
    //swap first and sec
    int temp = fir->val;
    fir->val = sec->val;
    sec->val = temp;
    return dummy->next;
}