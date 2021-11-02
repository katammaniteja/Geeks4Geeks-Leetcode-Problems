// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

// You are given a special linked list with N nodes where each node 
// has a next pointer pointing to its next node. You are also given 
// M random pointers, where you will be given M number of pairs denoting 
// two nodes a and b  i.e. a->arb = b.
// Construct a copy of the given list. The copy should consist of exactly 
// N new nodes, where each new node has its value set to the value of its 
// corresponding original node. Both the next and random pointer of the new 
// nodes should point to new nodes in the copied list such that the 
// pointers in the original list and copied list represent the same list 
// state. None of the pointers in the new list should point to nodes in 
// the original list.

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node* curr=head,*temp;
        while(curr!=NULL){
            temp=curr->next;
            Node* new_node=new Node(curr->data);
            curr->next=new_node;
            new_node->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr!=NULL){
            curr->next->arb=(curr->arb!=NULL)?(curr->arb->next):NULL;
            curr=curr->next->next;
        }
        curr=head;
        temp=head->next;
        Node* res=temp;
        while(curr->next->next!=NULL){
           curr->next=temp->next;
           curr=curr->next;
           temp->next=curr->next;
           temp=temp->next;
        }
        curr->next=NULL;
        return res;
   
    }

};