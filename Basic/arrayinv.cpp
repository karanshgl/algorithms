#include<iostream>

using namespace std;

int main(){
  int a[1000],b[1000];
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[a[i]]=i;
  }
  for(int i=0;i<n;i++) cout<<b[i];
}
