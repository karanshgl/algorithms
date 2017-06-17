#include<iostream>

using namespace std;

int max(int x, int y){
  return (x>y?x:y);
}

int main(){
  int arr[100],n,s=0, m=0;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];

  for(int i=0;i<n;i++){
    if(s+arr[i]>0) s+=arr[i];
    else{
      m=s;
      s=0;
    }
  }
  m=max(m,s);
  cout<<m<<endl;

}
