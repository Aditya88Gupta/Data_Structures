#include<iostream>
#include<cstdio>
using namespace std;

// Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head){
   if(head==NULL)
     return -1;
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL && fast->next!=NULL)
          fast=fast->next;
    }
    return slow->data;
}