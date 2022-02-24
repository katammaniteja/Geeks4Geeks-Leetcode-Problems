// https://leetcode.com/problems/sort-list/
class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head=new ListNode(0);
        ListNode* curr=head;
        while(head1 && head2){
            if(head1->val<=head2->val){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }
        }
        if(head1) curr->next=head1;
        else curr->next=head2;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head,*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(fast));
    }
};