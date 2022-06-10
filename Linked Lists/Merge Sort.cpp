// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1/#
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* head1,Node* head2){
        Node* head=new Node(0);
        Node* curr1=head1,*curr2=head2,*curr=head;
        while(curr1 && curr2){
            if(curr1->data<=curr2->data){
                curr->next=curr1;
                curr1=curr1->next;
            }
            else{
                curr->next=curr2;
                curr2=curr2->next;
            }
            curr=curr->next;
        }
        if(curr1!=NULL) curr->next=curr1;
        else if(curr2!=NULL) curr->next=curr2;
        return head->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        Node* slow=head,*fast=head,*temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        Node* start=mergeSort(head);
        Node* mid=mergeSort(slow);
        return merge(start,mid);
    }
};