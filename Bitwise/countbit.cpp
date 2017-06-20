#include<iostream>

using namespace std;

int count(int n){
  int sum=0;
  while(n){
    sum+=n&1;
    n>>=1;
  }
return sum;
}

int main(){
  int n;
  cin>>n;
  cout<<count(n);
  return 0;
}
