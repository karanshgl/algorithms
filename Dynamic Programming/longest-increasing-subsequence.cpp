#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int back(vector<int> &v){
  if(v.size()<0) return -1;
  return v[v.size()-1];
}


vector<int> lis(int arr[], int n){

  vector<int> *memo =  new vector<int> [n];

  for(int i=n-1;i>=0;i--){
    memo[i].push_back(arr[i]);
    for(int j=i-1;j>=0;j--){
      if(arr[j]<back(memo[i])){
        memo[i].push_back(arr[j]);
      }
    }
  }
  int maxIndex=0;
  for(int i=0;i<n;i++){
    if(memo[maxIndex].size()<memo[i].size()) maxIndex=i;
  }
  vector<int> ans = memo[maxIndex];
  delete [] memo;
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
  int arr[100], n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> ans = lis(arr,n);
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

}
