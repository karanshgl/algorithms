#include<iostream>
#include<deque>

using namespace std;


void kMax(int arr[],int size, int k){
  deque <int> Q;
  int i;
  for(i=0;i<k;i++){
    while(!Q.empty() && arr[i]>arr[Q.back()]) Q.pop_back();
    Q.push_back(i);
  }
  while(i<size){
    cout<<arr[Q.front()]<<" ";
    while(!Q.empty() && Q.front()<=i-k) Q.pop_front();

    while(!Q.empty() && arr[i]>arr[Q.back()]) Q.pop_back();
    Q.push_back(i);
    i++;
  }
  cout<<arr[Q.front()];
}


int main(){
  int n,arr[1000000],k;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  cin>>k;
  kMax(arr,n,k);

}
