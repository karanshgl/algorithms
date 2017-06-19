#include<iostream>
#include<limits.h>

using namespace std;


int main(){
  int arr[100],n,s=0, m=0;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];

  for(int i=0;i<n;i++){
    s = s + arr[i];
        if (m < s) m = s;
        if (s < 0)  s = 0;
  }
  cout<<m<<endl;

}
