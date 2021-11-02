

// Method 1
class Solution {
public:
    ListNode *prev=NULL;
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return prev;
        ListNode* tail=head->next;
        head->next=prev;
        prev=head;
        return reverseList(tail);
    }
};

//Method 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* rest_head=reverseList(head->next);
        ListNode* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return rest_head;
    }
};