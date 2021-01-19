#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;


class Queue{
    
    private:
    stack<int> Stack1;
    stack<int> Stack2;
    
    public:
    
    void Enqueue(int key){
        
        Stack1.push(key); // Push Elements in Stack1
    }
    
    int Dequeue(){
         
        if (Stack1.empty() && Stack2.empty()){ //Empty Queue 
            cout << "Q is empty"; 
            return -1; 
        } 
        
        if (Stack2.empty()){ 
            
            while (Stack1.empty() == false){ // Shifting contents of Stack1
                Stack2.push(Stack1.top());   // in Stack2 
                Stack1.pop(); 
            } 
        } 
        
        int item = Stack2.top(); 
        Stack2.pop();  
        return item;
    }    
};


int main(){
    
    Queue queue;
    vector<int> de;
    char ch;int num;
    int size=0;
    bool Invalid = false;
    bool flag = true;
    while(flag){
        
        cin>>ch;
        if(ch=='E'){
            cin>>num;
            queue.Enqueue(num);
            size+=1;
        }
        else if(ch=='D'){
            if(size==0){
                Invalid = true;
                break;
            }
            int temp = queue.Dequeue();
            de.push_back(temp);
            size-=1;
        }
        else if(ch=='N'){
            flag = false;
        }
        else{
            Invalid = true;
            break;
        }
    }
   
}