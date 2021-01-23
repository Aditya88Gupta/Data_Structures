
// Implementing fundamental operations of stack using queue

#include<iostream>
#include<Queue>
using namespace std;


class Stack{

    queue<int>Q;
    int size;
    public:
    Stack(){
        size=0;
    }
    void Push(int key);
    int Pop ();
    int Top();
};

void Stack::Push(int key){
    Q.push(key);         // O(1)
    size+=1;
}

int Stack::Pop(){        // O(n)

    if (size==0){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int Temp= size;
    int x;
    while(Temp>1){
        x = Q.front();
        Q.pop();
        Q.push(x);
        Temp-=1;
    }
    x = Q.front();
    Q.pop();
    size-=1;
    return x;
} 

int Stack::Top(){
    if (size==0){
        cout<<"Empty Stack"<<endl;
        return -1;
    }
    //cout<<size<<endl;
    return Q.back();
}

int main(){

    Stack stack; 
    int choice;bool flag = true;int num;
    while(flag){
        cout<<"1.)PUSH"<<endl;
        cout<<"2.)POP"<<endl;
        cout<<"3.)TOP"<<endl;
        cout<<"4.)EXIT"<<endl;
        cout<<"Enter Your Choice =";cin>>choice;
        switch(choice){
            case 1:
            int ele;
            cout<<"Enter The Element To Be Inserted =";
            cin>>ele;
            stack.Push(ele);
            break;
            case 2:
            num = stack.Pop();
            if(num!=0)
                cout<<"The Deleted Element Is = "<<num<<endl;
            break;
            case 3:
            cout<<"The Element at the Top is"<<endl;
            cout<<stack.Top()<<endl;
            break;
            case 4:
            flag = false;
            break;
            default:
            flag = false;            
        }
    }
    
}



