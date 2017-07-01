//A function to implement wavesort i.e. arr[i-1] >= arr[i] <= arr[i+1]

#include<iostream>

using namespace std;

void swap(int &x, int &y){
  //Function to swap two numbers
  int temp;
  temp=y; y = x; x = temp;
}

void wavesort(int arr[],int size){

  for(int i=0;i<size;i+=2){
  //i increases by 2 in every iteration, since we need to bring the peak element in the middle
    if(i+1<size && arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
    //If the element to the right is greater than the cur element, swap
    if(i-1>0&&arr[i-1]>arr[i]) swap(arr[i],arr[i-1]);
    //If element to the left is greater than the next element, swap
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
