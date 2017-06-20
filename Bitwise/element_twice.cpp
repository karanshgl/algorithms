#include<iostream>
#include<numeric>

using namespace std;

int operation(int x, int y){
  return x^y;
}

int findUnique(int arr[], int n){
  int res = accumulate(arr,arr+n,0,operation);
  return res;
}

int main(){
  int arr[]= { 1,2,3,4,1,2,3};
  int n = sizeof(arr)/sizeof(int);
  int res = findUnique(arr,n);
  cout<<res<<endl;
}
