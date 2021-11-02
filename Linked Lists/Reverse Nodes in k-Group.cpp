// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Given a linked list, reverse the nodes of a linked list k 
// at a time and return its modified list.
// k is a positive integer and is less than or equal to the 
// length of the linked list. If the number of nodes is not 
// a multiple of k then left-out nodes, in the end, should 
// remain as it is.

class Solution {
public:
    ListNode *reverse (ListNode *head, int k,int n){ 
        if(n<k) return head;
        ListNode* next=NULL,*prev=NULL,*curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            ListNode* rest_head=reverse(next,k,n-k);
            head->next=rest_head;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode *curr=head;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        return reverse(head,k,n);
    }
};