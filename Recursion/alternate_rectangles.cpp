#include<iostream>

using namespace std;
const int N=7;

void  print(char arr[][N]) {
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++) cout<<arr[i][j]<<" ";
    cout<<endl;
  }
}

void generate(char arr[][N], int low,int high, char pattern){
  if(high<=0) return;
  int j = low+high-1;
  for(int i=low;i<=j;i++) arr[i][j] = pattern;
  for(int i=low;i<=j;i++) arr[i][low] = pattern;
  for(int i=low;i<=j;i++) arr[j][i] = pattern;
  for(int i=low;i<=j;i++) arr[low][i] = pattern;

  if(pattern=='O') pattern = 'X';
  else pattern = 'O';

  generate(arr,low+1,high-2, pattern);

}

int main(){
  char arr[N][N]={};
  generate(arr,0,N,'O');
  print(arr);
  return 0;
}
