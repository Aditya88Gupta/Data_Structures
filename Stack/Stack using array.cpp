#include<iostream>
#include<cstdio>
using namespace std; 

#define Size 1000 

class Stack{ 
    
    int Top; 

public: 
    int arr[Size];  
    Stack() { 
        Top = -1; 
    } 
    bool Push(int x); 
    int Pop(); 
    void Traverse(); 
    bool CheckEmpty(); 
}; 

bool Stack::Push(int x){ 
    if (Top >= (Size - 1)){
        cout<<"Overflow"<<endl; 
        return false; 
    } 
    else { 
        arr[++Top] = x; 
        cout<<"Element Pushed"<<endl; 
        return true; 
    } 
} 

int Stack::Pop(){ 
    if (CheckEmpty()) { 
        cout<<"Underflow"<<endl; 
        return 0; 
    } 
    else { 
        int x = arr[Top--]; 
        return x; 
    } 
} 

void Stack::Traverse(){ 
    
    if (CheckEmpty()) { 
        cout<<"Empty";  
    } 
    else{ 
        int Temp = Top;
        while (Temp>=0){
            cout<<arr[Temp]<<" ";
            Temp-=1;
        } 
    } 
    cout<<endl;
} 

bool Stack::CheckEmpty(){ 
    return (Top < 0); 
} 


int main(){ 
    
    Stack obj; 
    int choice;bool flag = true;int num;
    while(flag){
        cout<<"1.)PUSH"<<endl;
        cout<<"2.)POP"<<endl;
        cout<<"3.)TRAVERSE"<<endl;
        cout<<"4.)EXIT"<<endl;
        cout<<"Enter Your Choice =";cin>>choice;
        switch(choice){
            case 1:
            int ele;
            cout<<"Enter The Element To Be Inserted =";
            cin>>ele;
            obj.Push(ele);
            break;
            case 2:
            num = obj.Pop();
            if(num!=0)
                cout<<"The Deleted Element Is = "<<num<<endl;
            break;
            case 3:
            cout<<"The Element(s) In The Stack(s) is/are..."<<endl;
            obj.Traverse();
            break;
            case 4:
            flag = false;
            default:
            flag = false;            
            }
    }
    
} 
