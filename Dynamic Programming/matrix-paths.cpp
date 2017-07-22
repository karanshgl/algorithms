//The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down
#include<iostream>
using namespace std;

int paths(int m, int n, int **memo){
  if(m==0||n==0) return memo[m][n]=1;

  if(memo[m][n]) return memo[m][n];

  memo[m][n] = paths(m-1,n,memo) + paths(m,n-1,memo);
  return memo[m][n];
}

int main(){
  int m, n;
  cin>>m>>n;

  int **memo = new int*[m];
  for(int i=0;i<m;i++) memo[i]=new int[n]();

  cout<<paths(m-1,n-1,memo)<<endl;
}
