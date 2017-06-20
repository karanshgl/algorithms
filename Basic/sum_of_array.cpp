#include<iostream>

using namespace std;

int sum[1000];
void shift(int a[], int s, int n){
  while(n--){
    a[n+s]=a[n];
  }
  for(int i=0;i<s;i++) a[i]=0;
}
int add(int a[], int b[], int n){
  int carry=0;
  for(int i=n-1;i>=0;i--){
    sum[i] = a[i] + b[i] + carry;
    if(sum[i]>9){
      carry = sum[i]/10;
      sum[i]%=10;
    }
    else carry=0;
  }
  if(carry){
    shift(sum,1,n);
    //for(int i=0;i<n+1;i++) cout<<sum[i]<<" ";
    sum[0]=carry;
    return 1;
  }
  return 0;
}



int main(){
  int n,m,a[1000],b[1000];
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  cin>>m;
  for(int i=0;i<m;i++) cin>>b[i];
  if(m>n) shift(a,m-n, n);
  else shift(b, n-m, m);
  m=max(m,n);
  if(add(a,b,m)) m++;
  for(int i=0;i<m;i++) cout<<sum[i]<<", ";
  cout<<"END"<<endl;
  return 0;
}
