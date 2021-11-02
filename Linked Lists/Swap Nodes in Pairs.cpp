// https://leetcode.com/problems/swap-nodes-in-pairs/

// Given a linked list, swap every two adjacent nodes and return its 
// head. You must solve the problem without modifying the values in the 
// list's nodes (i.e., only nodes themselves may be changed.)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head->next->next;
        ListNode* prev=head;
        head=head->next;
        head->next=prev;
        while(curr!=NULL &&  curr->next!=NULL){
            ListNode* rest=curr->next->next;
            prev->next=curr->next;
            prev=curr;
            curr->next->next=curr;
            curr=rest;
        }
        prev->next=curr;
        return head;
    }
};