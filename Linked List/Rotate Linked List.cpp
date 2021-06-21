#include<iostream>
#include<cstdio>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* tail=head;
        Node* track=head;
        while(track->next!=NULL)
            track=track->next;
        tail=track;
        track=head;
        int count=0;
        while(count<k){
            head=track->next;
            tail->next=track;
            tail=track;
            track->next=NULL;
            track=head;
            count++;
        }
        return head;
    }
};