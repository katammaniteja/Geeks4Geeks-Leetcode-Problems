// https://leetcode.com/problems/merge-k-sorted-lists/
// You are given an array of k linked-lists lists,
//  each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head,*tail;
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        if(head1->val<=head2->val){
            head=tail=head1;
            head1=head1->next;
        }
        else{
            head=tail=head2;
            head2=head2->next;
        }
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                tail->next=head1;
                tail=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=head2;
                head2=head2->next;
            }
        }
        if(head1==NULL) tail->next=head2;
        else tail->next=head1;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* head=merge(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            head=merge(head,lists[i]);
        }
        return head;
        
    }
};
