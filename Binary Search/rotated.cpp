#include<iostream>

using namespace std;

int elementSearch(int arr[], int low, int high, int ele){
  if(low>high) return -1;

  int mid = (low + high)/2;

  if(arr[mid]>ele) return elementSearch(arr,low,mid-1,ele);
  else if(arr[mid]<ele) return elementSearch(arr,mid+1,high,ele);
  else return mid;

}


int main(){
  int arr[100],n,pivot,e;

  cin>>n;

  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(i>0){
      if(arr[i+1]<arr[i]) pivot=i+1;
    }
  }

  cout<<"Enter the element to search\n";
  cin>>e;
  int iFirst = elementSearch(arr,0,pivot-1,e);
  int iSecond = elementSearch(arr,pivot,n,e);

  if(iFirst!=-1) cout<<iFirst<<endl;
  else if (iSecond!=-1) cout<<iSecond<<endl;
  else cout<<"Not Found ";
  return 0;
}
