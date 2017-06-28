#include<iostream>
#include<stack>
#include "stack.h"

using namespace std;

//stack <int> revStack;



void insertBottom(stack <int> &s, int data){
  if(s.size()==0){
    s.push(data);
    return;
  }
  int d=s.top();
  s.pop();
  insertBottom(s,data);
  s.push(d);
}


void stackReverse(stack<int> &s){
  if(s.size()==0){
    return;
  }
  int d = s.top();
  s.pop();
  stackReverse(s);
  insertBottom(s,d);
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
