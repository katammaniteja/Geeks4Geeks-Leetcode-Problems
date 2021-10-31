// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect. If the
//  two linked lists have no intersection at all, return null.

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
int intersection(Node* h1,Node* h2){
    int c1=0,c2=0;
    Node *curr1,*curr2;
    for(curr1=h1;curr1!=NULL;curr1=curr1->next) c1++;
    for(curr2=h2;curr2!=NULL;curr2=curr2->next) c2++;
    int d=abs(c1-c2);
    if(c1>c2){
        curr1=h1;
        while(d--)
            curr1=curr1->next;
    }
    else{
        curr2=h2;
        while(d--) curr2=curr2->next;
    }
    while(curr1!=NULL &&curr2!=NULL){
        if(curr1==curr2) return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}