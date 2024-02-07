/*
Program 2:
WAP to reverse a circular linked list use only pointer manipulation; also write functions for insertion(in beginning, in between, and last), deletion(in between and last) and printing the linked list. Use only front and last pointer.
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
        while(this->next != NULL){
            this->next = NULL;
            delete next;
        }
        cout<<"value for : "<<value<<" has been deleted."<<endl;
    }
};


void insertAthead(Node *& head, int value)
{

    Node *node = new Node(value);

    if(head == NULL)
    {
        node->next = node;
        head = node;
        return;
    }

    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
    head = node;
}

void insertAtTail(Node *&head, int value)
{

    Node *node = new Node(value);
    if(head == NULL){
        insertAthead(head, value);
        return;
    }

    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
}

void deleteAthead(Node *&head)
{
    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    
    Node *todelete = temp->next;
    temp->next = head->next;
    head = head->next;
    todelete->next = NULL;
    delete todelete;
}

void deletion(Node *&head, int pos)
{

    Node *temp = head;
    if(pos == 1){
        deleteAthead(head);
        return;
    }
    int count = 1;
    while(count != pos - 1){
        temp = temp->next;
        count++;
    }

    Node *nodetodelete = temp->next;
    temp->next = temp->next->next;
    nodetodelete->next = NULL;
    delete nodetodelete;

}

void insertAtPosition(Node *&tail, int element, int d){

    //if the list is empty
    if(tail == NULL){
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }

    else{

        Node *curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}


void deleteAtPosition(Node *&tail, int element){

    if(tail == NULL){
        cout<<"Empty List"<<endl;
    }

    Node *prev = tail;
    Node *curr = prev->next;
    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    //only 1 element is present which has to be deleted.
    if(curr == prev){
        tail = NULL;
    }

    //>=2 elements in the LL
    else if(curr == tail){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void print(Node *& head)
{

    Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);

    cout<<endl;
}


void reverseCLL(Node*& head)
{
    if(head != NULL) 
    {
        Node* prevNode = head;
        Node* forwardNode = head;
        Node* curNode = head->next;
        
        while(curNode != head) 
        {
            forwardNode = curNode->next;
            curNode->next = prevNode;
            head->next = curNode;
            prevNode = curNode;
            curNode = forwardNode;
        }

        head = prevNode;
    }
}


int main()
{
    Node *head = NULL;
    insertAthead(head, 10);
    insertAthead(head, 20);
    insertAthead(head, 30);
    insertAthead(head, 40);
    print(head);
    cout<<"After reversing : ";
    reverseCLL(head);
    print(head);
}