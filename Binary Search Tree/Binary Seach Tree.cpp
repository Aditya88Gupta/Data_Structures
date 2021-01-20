#include<iostream>
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
};

Node* BSearchTree::find(Node *cur,int key){

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

Node* BSearchTree::Next(Node *cur){

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

void BSearchTree::Insert(int val){

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


