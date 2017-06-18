#include<iostream>

using namespace std;

void swap(int &x, int &y){
  int temp;
  temp=y; y = x; x = temp;
}

void wavesort(int arr[],int size){

  for(int i=0;i<size;i+=2){

    if(arr[i]<arr[i+1]&&i+1<size) swap(arr[i],arr[i+1]);

    if(i-1>0&&arr[i-1]>arr[i]) swap(arr[i],arr[i-1]);

  }

}


int main(){
  int arr[100],n;
  cin>>n;

  for(int i=0;i<n;i++) cin>>arr[i];

  wavesort(arr,n);

  for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  return 0;

}
