// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* slow=head,*fast=head,*prev;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            prev=fast->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(fast!=slow) return;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            prev=prev->next;
        }
        prev->next=NULL;
    }
};