#include<iostream>

using namespace std;

double median(int a[], int b[], int a_low, int b_low, int a_high, int b_high){

  if(a_high-a_low==1&&b_high-b_low==1){
    return (1.0*(max(a[a_low],b[b_low])+min(a[a_high],b[b_high])))/2;
  }

  int a_mid=(a_low+a_high)/2;
  int b_mid=(b_low+b_high)/2;

  int aMid=a[a_mid];
  int bMid=b[b_mid];

  if(aMid==bMid) return aMid;

  if(aMid>bMid){
    a_high=a_mid;
    b_low=b_mid;
  }
  else{
    a_low=a_mid;
    b_high=b_mid;
  }

  return median(a,b,a_low,b_low,a_high,b_high);
}

int main(){
  int a[100],b[100],n,m;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  cout<<median(a,b,0,0,n-1,n-1)<<endl;
}
