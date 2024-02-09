/*
Program 4:
Given two linked lists with starting point P1 and P2, create a third linked list which has all the elements in sorted order. L1 and L2 are not sorted. Use insertion sort.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            delete next;
        }
        cout<<"Memory for value "<<value<<" has been deleted"<<endl;
    }
};

//insertion at head
void insertatHead(Node *&head, Node *&tail, int d){
    
    Node *temp = new Node(d);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head = temp;   //modifying the head pointer.

}


//traversal
void printList(Node * &head){

    Node *temp = head;
    while(temp != '\0'){

        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}


Node* insertionSort(Node* head)
{
    
    Node* ans=new Node(head->data);
    Node* curr=head->next;
    
    while(curr!=NULL){
        Node* next_node=curr->next;
        
        Node* temp=ans;
        Node* prev=NULL;
        
        while(temp!=NULL && temp->data < curr->data){
            prev=temp;
            temp=temp->next;
        }
        
        if(prev==NULL){
            curr->next=temp;
            ans=curr;
        }
        
        else if(temp==NULL){
            prev->next=curr;
            curr->next=NULL;
        }
        
        else {
            prev->next=curr;
            curr->next=temp;
        }
        
        curr=next_node;
    }
    
    return ans;
}

//merge two sorted linked lists
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* head = NULL;
    Node* tail = NULL;
    
    while(head1 != NULL and head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->next;
            }
            else
            {
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
                
            }
        }
    }
    
    while(head1 != NULL)
    {
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;
    }
    
    while(head2 != NULL)
    {
        tail->next = head2;
        tail = tail->next;
        head2 = head2->next;
    }
    
    return head;
}  


int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(7);
    Node* tail1 = node1;
    Node* tail2 = node2;

    insertatHead(node1, tail1, 4);
    insertatHead(node1, tail1, 2);
    insertatHead(node1, tail1, 9);
    insertatHead(node1, tail1, 3);

    insertatHead(node2, tail2, 12);
    insertatHead(node2, tail2, 7);
    insertatHead(node2, tail2, 10);
    insertatHead(node2, tail2, 15);

    //Before sorting 
    cout<<"Before sorting"<<endl;
    printList(node1);
    cout<<endl;
    printList(node2);
    cout<<endl;

    Node* ans1 = insertionSort(node1);
    Node* ans2 = insertionSort(node2);

    //After sorting
    cout<<"After sorting"<<endl;
    printList(ans1);
    cout<<endl;
    printList(ans2);
    cout<<endl;

    //After merging
    cout<<"After merging"<<endl;
    Node* root = sortedMerge(ans1, ans2);
    printList(root);
}