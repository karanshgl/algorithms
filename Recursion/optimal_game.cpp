#include<iostream>

using namespace std;

int min(int x, int y){
  return (x<y?x:y);
}

int max(int x, int y){
  return (x>y?x:y);
}

int score(int arr[], int be, int en){
  if(be>en) return 0;

  int ch1 = arr[be] + min(score(arr,be+2,en),score(arr,be+1,en-1));
  int ch2 = arr[en] + min(score(arr,be+1,en-1), score(arr,be,en-2));

  return max(ch1,ch2);
}

int main(){

  int arr[]={8,5,100,5,8};
  int en = sizeof(arr) / sizeof(int) -1;

  cout<<score(arr,0,en)<<endl;

  return 0;
}
