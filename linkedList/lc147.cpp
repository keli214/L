#include <vector>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*  sorted should point to the head of the sorted list, 
    head point to the current node that we are checking 
    for the current node, we are finding the node in sorted 
    that is prev node of curr*/
ListNode* insertionSortList(ListNode* head) {
    ListNode *sorted = new ListNode(0, nullptr);
    while(head){
        auto prev = sorted, curr = sorted->next;
        // < : increaseing order, > : decreasing order
        while(curr && curr->val < head->val){
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = head;
        auto temp = head->next;
        head->next = curr;
        head = temp;
    }
    return sorted->next;
}

