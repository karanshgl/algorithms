#include<iostream>

using namespace std;

int M,N;

void print(int arr[][10], int r){
  if(r==M) return;

  if(r%2==0){
    for(int i=0;i<N;i++) cout<<arr[r][i]<<", ";
    print(arr,r+1);
  }
  else{
    for(int i=N-1;i>=0;i--) cout<<arr[r][i]<<", ";
    print(arr,r+1);
  }
}

int main(){
  int arr[10][10];
  cin>>M>>N;
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++) cin>>arr[i][j];
  }
  print(arr,0);
  cout<<"END"<<endl;
  return 0;

}
