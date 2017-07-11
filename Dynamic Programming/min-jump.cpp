#include<iostream>

using namespace std;
const int inf = 10000;

int minJump(int arr[], int be, int en, int *memo){
//Function that returns the minimum number of jumps

  if(be>en) return 0; //base condition

  if(arr[be]==0) return inf; //if we cannot move forward

  if(memo[be]) return memo[be]; //if we have already computed the result

  int result = inf; //Minimization problem, initial result is infinite

  for(int j=1;j<=arr[be];j++){
    //Calculating all steps
    int jumps = 1 + minJump(arr,be+j,en,memo);
    result=min(jumps,result);
    //finding the minimum number of steps
  }
  memo[be] = result;
  return memo[be];
}

int main(){
  int arr[100];
  int n;
  cin>>n;

  for(int i=0;i<n;i++) cin>>arr[i];

  int *memo = new int[n]();
  cout<<minJump(arr,0,n-1,memo);
}
