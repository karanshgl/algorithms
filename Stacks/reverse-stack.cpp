#include<iostream>
#include<stack>
#include "stack.h"

using namespace std;

//stack <int> revStack;


void clear(stack <int> &s){
  while(s.size()) s.pop();
}

void stackReverse(stack<int> &s){

static stack <int> revStack;
if(s.size()==0){
  s=revStack;
  clear(revStack);
  return;
}
revStack.push(s.top());
s.pop();
stackReverse(s);
}


int main(){

  stack <int> myStack;
  int n,num;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num;
    myStack.push(num);
  }
  showStack(myStack);
  stackReverse(myStack);
  showStack(myStack);
  return 0;
}
