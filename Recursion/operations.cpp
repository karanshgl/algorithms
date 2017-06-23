#include<iostream>

using namespace std;

int cnt;

bool allzero(char arr[]){

  for(int i=0;arr[i]!='\0';i++) if(arr[i]=='1') return false;
  return true;

}

void check(char arr[], int i){
  if(i==-1){
    return;
  }
  if(allzero(arr)){
    return;
  }
  if(arr[i]=='0') check(arr,i-1);
  else{
    cnt++;
  for(int j=i;j>=0;j--){
    if(arr[j]=='0') arr[j]='1';
    else if(arr[j]=='1') arr[j]='0';
  }
  check(arr,i-1);
}
}

int main(){
  char arr[100000],n=0;
  cin>>arr;
  while(arr[n]!='\0') n++;
  check(arr,n-1);
  cout<<cnt<<endl;
}
