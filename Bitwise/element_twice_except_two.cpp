#include<iostream>
#include<numeric>

using namespace std;

int operation(int x, int y){
  return x^y;
}


int findUnique(int arr[], int n){
  int res = accumulate(arr,arr+n,0,operation);
  return res;
}

void divide(int arr[], int n, int j){
  int a[1000],b[1000],p=0,q=0;
  for(int i=0;i<n;i++){
    if(arr[i]&j) p^=arr[i];
    else q^=arr[i];
  }
 cout<<p<<" and "<<q<<endl;;

}

int main(){
  int arr[]= {1,2,3,4,1,2,3,5,5,6};
  int n = sizeof(arr)/sizeof(int);
  int res = findUnique(arr,n);
  int j=res&(-res); //SET BIT
  divide(arr,n,j);
  return 0;
}
