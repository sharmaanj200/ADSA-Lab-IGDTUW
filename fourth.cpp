/*
Program 4:
Given two linked lists with starting point P1 and P2, create a third linked list which has all the elements in sorted order. L1 and L2 are not sorted. Use insertion sort.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};


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
    
}