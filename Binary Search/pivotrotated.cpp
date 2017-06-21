#include<iostream>

using namesapce std;

int findPivot(int arr[], int low, int high){
  if (high < low)  return -1;
  if (high == low) return low;

  int mid = (low + high)/2;
  if (mid < high && arr[mid] > arr[mid + 1])
      return mid;
  if (mid > low && arr[mid] < arr[mid - 1])
      return (mid-1);
  if (arr[low] >= arr[mid])
      return findPivot(arr, low, mid-1);
  return findPivot(arr, mid + 1, high);

}

int main(){
    int n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<findPivot(a,0,n-1)<<endl;
}
