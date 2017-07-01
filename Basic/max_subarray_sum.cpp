#include<iostream>

using namespace std;

int maxArr(int a[], int size){
  //A function which returns the maximum continuous sum in an array
  int curSum=0, maxSum=0;
  curSum=a[0];
  maxSum=a[0];
  for(int i=1;i<size;i++){
    curSum=max(a[i],curSum+a[i]);
    //returns the current maximum sum
    maxSum=max(maxSum,curSum);
    //checks the absolute max sum
  }
  return maxSum;
}

int main(){
  int arr[100],n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];

  cout<<maxArr(arr,n);
}
