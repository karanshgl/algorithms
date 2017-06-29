#include<iostream>
#include<stack>

using namespace std;

stack <int> a,b;

void push_front(int ele){
  a.push(ele);
}

void pop_front(){
  a.pop();
}

void push_back(int ele){
  while(!a.empty()){
    b.push(a.top());
    a.pop();
  }
a.push(ele);
while(!b.empty()){
  a.push(b.top());
  b.pop();
}
}

void pop_back(){
  while(a.size()>1){
    b.push(a.top());
    a.pop();
  }
  a.pop();
  while(!b.empty()){
    a.push(b.top());
    b.pop();
  }
}

void showQueue(stack <int> stk){
while(!stk.empty()){
  cout<<stk.top()<<" ";
  stk.pop();
}
}

int main(){
  int n;
  cin>>n;
for(int i=0;i<n;i++) push_back(i);
showQueue(a);
}
