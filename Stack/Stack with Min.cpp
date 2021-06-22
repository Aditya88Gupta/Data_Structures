class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


/*returns min element from stack*/
int _stack :: getMin(){
    if(s.empty())
      return -1;
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
      return -1;
    int tmp=s.top();
    s.pop();
    if(tmp<minEle){
        int tmp2=minEle;
        minEle = 2*minEle - tmp;
        tmp=tmp2;
    }
    return tmp; 
}

/*push element x into the stack*/
void _stack::push(int x){
   if(s.empty()){
       minEle=x;
   }
   else if(minEle>x){
       int tmp=2*x - minEle;
       minEle=x;
       x=tmp;
   }
   s.push(x);
}