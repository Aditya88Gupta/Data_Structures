
// Implementation of Binary Search Tree which satisfies the AVL property

#include<iostream>
using namespace std;

struct Node{
    
    int key;
    int height;
    Node *Left,*Right,*Parent;
};

class BSearchTree{

    Node *root;
    public:
    BSearchTree(){
        root = NULL;
    }
    Node * find(Node *cur,int key);
    Node * Next(Node *cur);
    Node *LeftDescendant(Node *cur);
    Node *RightAncestor(Node *cure);
    void RangedSearch(int lower,int upper,Node *Root);
    void Insert(int val);
    void AVLInsert(int val);
    void AVLDelete(int val);
    void Rebalance(Node* cur);
    void AdjustHeight(Node* cur);
    void RebalanceLeft(Node* cur);
    void RebalanceRight(Node* cur);
    void RotateLeft(Node* cur);
    void RotateRight(Node* cur);
    void Delete(int val);
    void PostTrav(Node *cur);
    void PreTrav(Node *cur);
    void InTrav(Node *cur);
    Node* Root();
};

Node* BSearchTree::Root(){
    return root;
}

void BSearchTree::AdjustHeight(Node* cur){  
    // O(1)
    if(cur!=NULL){
        int LH=0,RH=0; 
        if(cur->Left!=NULL)
        LH = ((cur->Left)->height);
        if(cur->Right!=NULL)
        RH = ((cur->Right)->height);
        cur->height = 1+max(LH,RH);
    }
}

void BSearchTree::RotateRight(Node* cur){  // O(1)
    Node* Left = cur->Left;
    Left->Parent = cur->Parent;
    cur->Left = Left->Right;
    Left->Right = cur;
    if(cur->Parent==NULL){
        root = Left;
    }
    else if((Left->Parent)->key>Left->key)
       (Left->Parent)->Left = Left;
    else
       (Left->Parent)->Right = Left;
    cur->Parent = Left;
    
}

void BSearchTree::RotateLeft(Node* cur){  // O(1)
    Node* Right = cur->Right;
    Right->Parent = cur->Parent;
    cur->Right = Right->Left;
    Right->Left = cur;
    if(cur->Parent==NULL){
        root = Right;
    }
    else if((Right->Parent)->key>Right->key)
       (Right->Parent)->Left = Right;
    else
       (Right->Parent)->Right = Right;
    cur->Parent = Right;
    
}

void BSearchTree::RebalanceRight(Node* cur){  // O(1)
    Node* Left = cur->Left;
    Node* Temp = Left->Right;
    int LLH=0,LRH=0;
    if(Left->Left!=NULL)
       LLH = (Left->Left)->height;
    if(Left->Right!=NULL)
       LRH = (Left->Right)->height;
    if (LRH>LLH)
        RotateLeft(Left);
    RotateRight(cur);
    AdjustHeight(cur);
    AdjustHeight(Left);
    AdjustHeight(Temp);
}

void BSearchTree::RebalanceLeft(Node* cur){  // O(1)
    Node* Right = cur->Right;
    Node* Temp = Right->Left;
    int RLH=0,RRH=0;
    if(Right->Left!=NULL)
       RLH = (Right->Left)->height;
    if(Right->Right!=NULL)
       RRH = (Right->Right)->height;
    if (RLH>RRH)
        RotateRight(Right);
    RotateLeft(cur);
    AdjustHeight(cur);
    AdjustHeight(Right);
    AdjustHeight(Temp);
}

void BSearchTree::Rebalance(Node* cur){   // O(log(n))
    Node* P = cur->Parent;
    int LH=0,RH=0; 
    if(cur->Left!=NULL)
       LH = ((cur->Left)->height);
    if(cur->Right!=NULL)
       RH = ((cur->Right)->height);   
    if (LH>RH+1)
       RebalanceRight(cur);
    else if(LH+1<RH)
        RebalanceLeft(cur);
    AdjustHeight(cur);    
    if (P!=NULL)
       return Rebalance(P);    
}

Node* BSearchTree::find(Node *cur,int key){                  
                                        // O(log(n))
    if (cur->key == key)               // Normal Binary Search
        return cur;   
    else if(cur->key < key){
        if (cur->Right != NULL)
            return find(cur->Right,key);
        return cur;
    }
    else{
        if (cur->Left != NULL)
            return find(cur->Left,key);
        return cur;
    }   
}

Node* BSearchTree::LeftDescendant(Node *cur){

    if (cur->Left == NULL)          // Can't go more left
        return cur;
    else
       return LeftDescendant(cur->Left);    
}

Node* BSearchTree::RightAncestor(Node *cur){

     if (cur->Parent == NULL)       // Condition for Max
       return NULL;
    if (cur->key<(cur->Parent)->key)
        return cur->Parent;
    else    
       return RightAncestor(cur->Parent);
}

Node* BSearchTree::Next(Node *cur){      // O(log(n))

    if (cur->Right != NULL)             // If Right child exists, then go right then left until can't go further left 
       return LeftDescendant(cur->Right);
    else
       return RightAncestor(cur);      // If Right child does not exists, then find first ancestor with a greater key
}

void BSearchTree::RangedSearch(int lower,int upper,Node *Root){
    Node* cur = find(Root,lower);
    if(cur->key>lower)
      cout<<cur->key<<" ";
    while (cur->key<=upper){
        if(cur->key>=lower)
           cout<<cur->key<<" ";
        cur = Next(cur);
    }  
}

void BSearchTree::Insert(int val){    // O(log(n))

    Node *new_node = new Node();
    new_node->key = val;
    //new_node->height = 1;
    if (root==NULL){
        new_node->height = 1;
        new_node->Left=new_node->Right=NULL;
        new_node->Parent = NULL;
        root = new_node;
    }
    else{
        Node *Cur = find(root,val);
        if(Cur->key>val)
          Cur->Left = new_node;
        else
          Cur->Right = new_node;
        new_node->Parent = Cur;  
    }
}

void BSearchTree::AVLInsert(int val){    
    Insert(val);
    Node* cur = find(Root(),val);
    Rebalance(cur);
}


void BSearchTree::Delete(int key){     // O(log(n))
    Node* Temp = find(root,key);
    if (Temp->Right == NULL){         // Promote Left Child
        if(Temp->Left != NULL)       // Check if it's a Leaf Node 
            (Temp->Left)->Parent = Temp->Parent;
        if(Temp->key>(Temp->Parent)->key){
            (Temp->Parent)->Right = Temp->Left;
        }
        else{
            (Temp->Parent)->Left = Temp->Left;
        }
        delete Temp;                
    }
    else{
        Node* next = Next(Temp);     
        if(next->Right!=NULL){       // Promote Right Child of Next if it exists
            (next->Right)->Parent = next->Parent;
            (next->Parent)->Left = next->Right;
        }
        next->Parent = Temp->Parent; // Replace Temp with it's next 
        next->Left = Temp->Left; 
        next->Right = Temp->Right;
        if(Temp->Left!=NULL)
            (Temp->Left)->Parent = next;
        if(Temp->Right!=NULL)
            (Temp->Right)->Parent = next;
        if(Temp->key>(Temp->Parent)->key){
            (Temp->Parent)->Right = next;
        }
        else{
            (Temp->Parent)->Left = next;
        }
        delete Temp;    
    }
}

void BSearchTree::AVLDelete(int val){  
    Node* cur = find(Root(),val);  
    cur = (Next(cur))->Parent;
    Delete(val);
    Rebalance(cur);
}

void BSearchTree::PreTrav(Node *cur){   // O(n)
    
    if (cur==NULL)
       return;
    
    cout<<cur->key<<" ";
    PreTrav(cur->Left);
    PreTrav(cur->Right);
}

void BSearchTree::PostTrav(Node *cur){   // O(n)
    
    if (cur==NULL)
       return;

    PostTrav(cur->Left);
    PostTrav(cur->Right);
    cout<<cur->key<<" ";
}

void BSearchTree::InTrav(Node *cur){   // O(n)
    
    if (cur==NULL)
       return;

    InTrav(cur->Left);
    cout<<cur->key<<" ";
    InTrav(cur->Right);
}


int main(){
    
    BSearchTree tree;
    int choice;int ele;
    bool flag = true;
    int x;
    while(flag){

        cout<<"1.)Insert"<<endl;
        cout<<"2.)Delete"<<endl;
        cout<<"3.)Infix Traversal"<<endl;
        cout<<"4.)Prefix Traversal"<<endl;
        cout<<"5.)Postfix Traversal"<<endl;
        cout<<"6.)Range Search"<<endl;
        cout<<"7.)Exit"<<endl;
        cout<<"Enter Your Choice=";cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter The Element To Be Inserted =";
                cin>>ele;
                tree.AVLInsert(ele);
                break;
            case 2:
                cout<<"Enter The Element To Be Deleted =";
                cin>>x;
                tree.AVLDelete(x);
                break;
            case 3:
                tree.InTrav(tree.Root());
                cout<<endl;
                break;
            case 4:
                tree.PreTrav(tree.Root());
                cout<<endl;
                break; 
            case 5:
                tree.PostTrav(tree.Root());
                cout<<endl;
                break;
            case 6:
                int l,u;
                cout<<"Enter lower bound=";cin>>l;
                cout<<"Enter upper bound=";cin>>u;
                tree.RangedSearch(l,u,tree.Root());
                cout<<endl;
                break;    
            case 7:
                flag = false; 
                break;   
            default:
                flag = false;
                break;
        }
    }
}


