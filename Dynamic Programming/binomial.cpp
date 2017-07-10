#include<iostream>
using namespace std;

int combination(int n, int k, int **memo){
  if(k==0||n==k) return memo[n][k]=1;

  if(memo[n][k]) return memo[n][k];

  memo[n][k] = combination(n-1,k-1,memo) + combination(n-1,k,memo);

  return memo[n][k];
}

int main(){
  int n,k;
  cin>>n>>k;
  int **memo = new int*[n+1];

  for(int i=0;i<=n;i++){
    memo[i] = new int[k+1]();
  }
  cout<<combination(n,k,memo);
}
