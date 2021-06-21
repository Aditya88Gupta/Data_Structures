#include<iostream>
#include<cstdio>
using namespace std;


struct Node{
    int data;
    struct Node *next;
}

class Solution{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head){
        Node* prev=head;
        Node* next=head->next;
        prev->next=NULL;
        while(next!=NULL){
            Node* tmp = next->next;
            next->next=prev;
            prev=next;
            next=tmp;
        }
        return prev; 
    }
    
};