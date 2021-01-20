#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Node{
    int key;
    Node* next;
};

class Queue{
    
    private:
    Node *front,*rear;
    
    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int key);
    int Dequeue();
    void Traverse();
};

void Queue::Enqueue(int key){
        
    Node* new_node = new Node();
    if(front == NULL && rear == NULL){
        new_node-> key = key;
        front = new_node;
        rear = new_node;
    }
        
    new_node-> key = key;
    rear-> next = new_node;
    rear = new_node;
}
    
int Queue::Dequeue(){
    
    if(front == NULL){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int item = front->key;
    Node* Temp = front;
    front = front->next;
    if(front==NULL) // After Deletion if empty 
        rear=NULL;
    delete(Temp);// Clearing Memory 
    return item;
}

void Queue::Traverse(){

    if(front == NULL)
        cout<<"Empty Queue";
    else{
        Node *track = front;
        while(track!=NULL){
            cout<<track->key<<" ";
            track = track->next; 
        }
    }    
    cout<<endl;
}



int main(){
    
    Queue queue;
    int choice;int ele;
    bool flag = true;
    int x;
    while(flag){
        cout<<"1.)Enqueue"<<endl;
        cout<<"2.)Dequeue"<<endl;
        cout<<"3.)Traverse"<<endl;
        cout<<"4.)Exit"<<endl;
        cout<<"Enter Your Choice=";cin>>choice;
        switch(choice){
            case 1:
                cin>>ele;
                queue.Enqueue(ele);
                break;
            case 2:
                x = queue.Dequeue();
                cout<<"Element Dequeued:"<<x<<endl;
                break;
            case 3:
                queue.Traverse();
                break;
            /*case 4:
                cout<<GetSize(queue)<<endl;
                break; */ 
            default:
                flag = false;
                break;
        }
    }
}
    
   
    
   
