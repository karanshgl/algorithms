#include<iostream>
#include<algorithm>

using namespace std;

bool check(int arr[], int &n, int x, int &c){
  int previous=arr[0],nCow=1;
  for(int i=1;i<n;i++){
    if(arr[i]-previous>=x){
      previous=arr[i];
      nCow++;
      if(nCow==c) return true;
    }
  }
  return false;
}


int distance(int arr[], int n, int c){

  int low=0,high=arr[n-1]-arr[0]+1, mid;

  while(low<high-1){
    mid=(low+high)/2;
    if(check(arr,n,mid,c)) low=mid;
    else high=mid;
  }
return low;
}

int main(){
  int n,arr[100000],c,t;
  cin>>t;
  while(t--){
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    cout<<distance(arr,n,c)<<endl;
  }
  return 0;
}
