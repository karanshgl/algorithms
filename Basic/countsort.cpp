#include<iostream>
#define RANGE 1000000
using namespace std;

int count[RANGE];


void countsort(int a[], int n){
  int i;
  int output[RANGE];
  for(i=1;i<RANGE;i++){
    count[i]+=count[i-1];
  }
  for(i=0;i<n;i++){
    output[count[a[i]]-1]=a[i];
    count[a[i]]--;
  }
  for(i=0;i<n;i++) cout<<output[i]<<" ";
}

int main(){
  int a[RANGE],n,m=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    count[a[i]]++;
  }
  countsort(a,n);
}
