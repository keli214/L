struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next){
        val = _val;
        next = _next;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0, l1);
        ListNode* res = dummy;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            res->next = new ListNode(digit);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* valid = l1 ? l1 : l2;
        while(valid){
            int sum = valid->val + carry;
            int digit = sum%10;
            carry = sum/10;
            res->next = new ListNode(digit);
            res = res->next;
            valid = valid->next;
        }
        if(carry){
            ListNode* carryDigit = new ListNode(1, nullptr);
            res->next = carryDigit;
        }
        return dummy->next;
        
    }