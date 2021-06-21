#include<iostream>
#include<cstdio>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};


void removeLoop(Node* head){
    // Detect Loop
    Node* track = head;
    Node* track_double = head;
    while (track!=NULL && track_double!=NULL){
        track=track->next;
        track_double=track_double->next;
        if (track_double!=NULL)
            track_double=track_double->next;
        if (track==track_double)
            break;
    }
    if (track==NULL || track_double==NULL)
        return;
    // If loop is present      
    int Count=1;
    track=track->next;
    while (track!=track_double){
        Count++;
        track=track->next;
    }
    // Count is the number of nodes in the loop
    track=head;
    track_double=head;
    // Take a pointer to the Count th node
    for(int i=0;i<Count;i++){
        track_double=track_double->next;
    }
    // Pointers will meet at the start of the lopp
    while(track!=track_double){
        track_double=track_double->next;
        track=track->next;
    }  
    track=track->next;
    while (track->next!=track_double)
        track=track->next;
    track->next=NULL;
}