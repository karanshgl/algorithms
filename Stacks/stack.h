#include<iostream>

using namespace std;

void showStack(stack <int> s){

  while(s.size()){
    cout<<s.top()<<" ";
    s.pop();
  }
cout<<endl;
}
