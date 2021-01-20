#include<iostream>
#include<cstdio>
using namespace std;

#define Size 100

class Queue{ 
    public: 
    int size;
    int front,rear;
    unsigned capacity;
    int* array; 
}; 
   
Queue* createQueue(unsigned num){

    Queue* queue = new Queue();     
    queue->capacity = num; 
    queue->front = queue->rear = -1; 
    queue->size = 0;  
    queue->array = new int[(queue->capacity * sizeof(int))]; 
    return queue; 
} 
 
void Enqueue(Queue* queue, int item){ 
     
    if(queue->size ==0)
        queue->front=0;
    else if(queue->size==queue->capacity){
        cout<<"Overflow"<<endl;  
        return;
    }
    queue->rear = (queue->rear + 1); 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    
} 
    
int Dequeue(Queue* queue){ 

    if(queue->size == 0){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1); 
    queue->size = queue->size - 1; 
    return item;  
}
    
void Traverse(Queue* queue){
    //cout<<"Elements in the queue are:"<<endl;
    int track = queue->front;
    while(track<=queue->rear){
        cout<<queue->array[track]<<" ";
        track+=1;
    }
    cout<<endl;
}

int GetSize(Queue *queue){
    return queue->size;
}
    

int main(){
    
    Queue* queue = createQueue(Size);
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
                Enqueue(queue,ele);
                break;
            case 2:
                x = Dequeue(queue);
                cout<<"Element Dequeued:"<<x<<endl;
                break;
            case 3:
                Traverse(queue);
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