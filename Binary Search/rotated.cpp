#include<iostream>

using namespace std;

int elementSearch(int arr[], int low, int high, int ele){
  if(low>high) return -1;

  int mid = (low + high)/2;

  if(arr[mid]==ele) return mid;

  if(arr[low]<arr[mid]){
    if(arr[low]<=ele && arr[mid]>=ele) return elementSearch(arr,low,mid-1,ele);
    else return elementSearch(arr,mid+1,high,ele);
  }
  else{
    if(arr[mid]<=ele && arr[high]>=ele) return elementSearch(arr,mid+1,high,ele);
    else return elementSearch(arr,low,mid-1,ele);
  }
}


int main(){
  int arr[100],n,pivot,e;

  cin>>n;

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<"Enter the element to search\n";
  cin>>e;
  int index = elementSearch(arr,0,n-1,e);
  cout<<index;
  return 0;
}
