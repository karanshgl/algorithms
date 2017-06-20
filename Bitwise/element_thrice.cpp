#include<iostream>

using namespace std;

const int BITS = 32;
int bit[BITS];

void addBits(int n){
  int i=0;
  while(n){
    bit[i]+=n&1;
    ++i;
    n=n>>1;
  }
}

int calBits(){
  int res=0;
 for(int i=0;i<BITS;i++){
    res+=(bit[i]%3)*(1<<i);
  }
  return res;
}

int res(int a[], int n){
  int j=1,b,c=0;
  for(int i=0;i<n;i++){
    addBits(a[i]);
  }

  return calBits();
}


int main(){
  int arr[]={102400000,6,6,6};
  int n = sizeof(arr) / sizeof(int);
  cout<<res(arr,n)<<endl;
  return 0;
}
