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

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    int Count=1;
    Node* track=head;
    while(track->next!=NULL){
        Count++;
        track=track->next;
    }
    int fromStart = Count-n+1;
    if(Count<n)
      return -1;
    Count=1;
    track=head;
    while(track->next!=NULL){
        if(Count==fromStart)
          break;
        Count++;
        track=track->next;
    }
    return track->data;
}