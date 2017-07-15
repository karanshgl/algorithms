//Given an array of integers and a sum, the task is to print all subsets of given array with sum equal to given sum.

#include<iostream>
#include<vector>

using namespace std;


//Recursive Sol, O(exp)
int target;
void sumSet(int arr[], int be, int en, int sum, vector<int> subSet){
  if(be>en && sum!=target) return;
  if(sum==target){
    for(int i=0;i<subSet.size();i++)cout<<subSet[i]<<" ";
    cout<<endl;
    return;
  }

  sumSet(arr,be+1,en,sum,subSet);
  if(sum+arr[be]<=target){
    subSet.push_back(arr[be]);
    sumSet(arr,be+1,en,sum+arr[be],subSet);
  }
}


//DP
void makeTable(int arr[], int n, int sum,bool **dp){
  //Fills the table bool dp
  for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
      if(j==0){
        dp[i][j]=1; //empty set can always be a subset with sum 0
        continue;
      }
      if(i>0 && arr[i]>j){ //If it was possible in subset it is possible in the superset
        dp[i][j] = dp[i-1][j];
      }
      else if(j-arr[i]==0){
        dp[i][j]=1; //If sum is equal to the element
      }
      else if(j-arr[i]>0 && i>0){
        if(dp[i-1][j-arr[i]]) dp[i][j]=1; //Subtract and check if possible
      }
    }
  }
}

void print(bool **dp,int row, int col,int arr[] ,vector<int> subSet){
  if(col<0||row<0) return;
  if((col-arr[row])==0){
    subSet.push_back(arr[row]);
    for(int i=0;i<subSet.size();i++) cout<<subSet[i]<<" ";
    cout<<endl;
    subSet.clear();
    print(dp,row-1,col,arr,subSet);
    return;
  }
  if(col==0){
    for(int i=0;i<subSet.size();i++) cout<<subSet[i]<<" ";
    cout<<endl;
    return;
  }
  print(dp,row-1,col,arr,subSet);
  if(dp[row][col]){
    subSet.push_back(arr[row]);
    print(dp,row-1,col-arr[row],arr,subSet);
  }

}


void printSets(int arr[], int n, int sum){

  bool **dp = new bool*[n];
  for(int i=0;i<n;i++) dp[i]=new bool[sum+1]();

  makeTable(arr,n,sum,dp);
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<=sum;j++) cout<<dp[i][j]<<" ";
  //   cout<<endl;
  // }
  vector<int> subSet;
  print(dp,n-1,sum,arr,subSet);

}

int main(){
  int n,arr[1000];
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  cin>>target;
  // vector<int> subSet;
  // sumSet(arr,0,n,0,subSet);
  printSets(arr,n,target);
}
