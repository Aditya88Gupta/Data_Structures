
// Implementation of Binary Search Tree

#include<iostream>
#include<limits>
using namespace std;

struct Node{
    
    int key;
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
    void Delete(Node* Temp);
    void PostTrav(Node *cur);
    void PreTrav(Node *cur);
    void InTrav(Node *cur);
    Node* Merge(Node* R1,Node* R2);
    Node* MWR(Node* R1,Node* R2,Node* T);    // Merge With Root
    void Split(Node* cur,int key,Node* &R1,Node* &R2);
    Node* Root();
    void SetRoot(Node* New);
};

Node* BSearchTree::Root(){
    return root;
}
void BSearchTree::SetRoot(Node* New){
    root=New;
    root->Parent=NULL;
}

Node* BSearchTree::find(Node *cur,int key){                  
                                        // O(Height(Tree))
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

Node* BSearchTree::Merge(Node* R1,Node* R2){
    int Inf=numeric_limits<int>::max();   // Max value int can take 
    Node* newroot= find(R1,Inf);         // Find node with max value
    Delete(newroot);
    return MWR(R1,R2,newroot);
}

Node* BSearchTree::MWR(Node* R1,Node* R2,Node* T){
    T->Left=R1;                         // All nodes of R1 are smaller than R2
    T->Right=R2;
    T->Parent=NULL;
    R1->Parent=R2->Parent=T;
    return T;
}

void BSearchTree::Split(Node* R,int key,Node* &R1,Node* &R2){

    if (R==NULL){
        R1=R2=NULL;
    }
    if (key<R->key){
        Split(R->Left,key,R1,R2);
        R2=MWR(R2,R->Right,R);
    }
    if(key>R->key){
        Split(R->Right,key,R1,R2);
        R1=MWR(R->Left,R1,R);
    }
    else{
        R1=R->Left;
        R2=R->Right;
    }

}

Node* BSearchTree::LeftDescendant(Node *cur){

    if (cur->Left == NULL)          // Can't go more left
        return cur;
    else
       LeftDescendant(cur->Left);    
}

Node* BSearchTree::RightAncestor(Node *cur){

     if (cur->Parent == NULL)       // Condition for Max
       return NULL;
    if (cur->key<(cur->Parent)->key)
        return cur->Parent;
    else    
       return RightAncestor(cur->Parent);
}

Node* BSearchTree::Next(Node *cur){      // O(Height(Tree))

    if (cur->Right != NULL)             // If Right child exists, then go right then left until can't go further left 
       return LeftDescendant(cur->Right);
    else
       return RightAncestor(cur);      // If Right child does not exists, then find first ancestor with a greater key
}

void BSearchTree::RangedSearch(int lower,int upper,Node *Root){   
                                      // O(n)
    Node* cur = find(Root,lower);
    if(cur->key>lower)
      cout<<cur->key<<" ";
    while (cur->key<=upper){
        if(cur->key>=lower)
           cout<<cur->key<<" ";
        cur = Next(cur);
    }  
}

void BSearchTree::Insert(int val){    // O(Height(Tree))

    Node *new_node = new Node();
    new_node->key = val;
    if (root==NULL){
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

void BSearchTree::Delete(Node* Temp){     // O(Height(Tree))
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
                tree.Insert(ele);
                break;
            case 2:
                cout<<"Enter The Element To Be Deleted =";
                cin>>x;
                tree.Delete(tree.find(tree.Root(),x));
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
    /*Node *R1,*R2;
    tree.Split(tree.Root(),6,R1,R2);
    BSearchTree LeftSubTree,RightSubTree;
    LeftSubTree.SetRoot(R1);
    RightSubTree.SetRoot(R2);
    LeftSubTree.InTrav(LeftSubTree.Root());
    cout<<endl;
    RightSubTree.InTrav(RightSubTree.Root());*/
}


