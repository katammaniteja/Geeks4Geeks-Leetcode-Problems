// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Given a linked list of size N. The task is to reverse every k nodes 
// (where k is an input to the function) in the linked list. If the number 
// of nodes is not a multiple of k then left-out nodes, in the end, should 
// be considered as a group and must be reversed.

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        struct node* next=NULL,*prev=NULL,*curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            struct node* rest_head=reverse(next,k);
            head->next=rest_head;
        }
        return prev;
    }
};