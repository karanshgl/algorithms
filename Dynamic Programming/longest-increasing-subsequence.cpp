#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

const int inf = 100000;

int lis(int arr[], int n){
//computes the length of lis ending at en
  int dp[n]={};
  for(int i=0;i<n;i++) dp[i] = 1;
  for(int i=0;i<n;i++){
    //computes the length of lis ending at the ith element
    for(int j=0;j<i;j++){
      if(arr[i]>arr[j] && dp[i]<dp[j]+1){
        dp[i]=dp[j]+1;
      }
    }
  }
  int res = 0;
  for(int i=0;i<n;i++) res = max(res,dp[i]);

  return res;
}

int main(){
  int arr[100000], n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<lis(arr,n)<<endl;
}
