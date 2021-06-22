
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:

    Node* Reverse(Node* head){
        Node* prev=head;
        Node* next=head->next;
        prev->next=NULL;
        while(next!=NULL){
            Node* tmp=next->next;
            next->next=prev;
            prev=next;
            next=tmp;
        }
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        Node *slow=head;
        Node* fast=head;
        // 1 element only
        if(head->next==NULL)
            return true;
        // 2 elements only    
        if((head->next)->next==NULL){
            if(head->data==(head->next)->data)
                return true;
            return false;    
        }    
        int Count=1;
        bool Odd=true;
        while(fast->next!=NULL){
            Count++;
            slow=slow->next;
            fast=fast->next;
            if(fast->next==NULL)
               Odd=false;
            if(fast->next!=NULL)
               fast=fast->next;
        }
        fast=head;
        if(Odd)
           Count=Count*2-1;
        else
           Count=(Count-1)*2;
        //cout<<Count;
        if(Count%2!=0)
            slow=slow->next;
        slow=Reverse(slow);    
        while(slow!=NULL){
            if(fast->data!=slow->data)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};