//A program to implement the count sort algorithm

#include<iostream>
#define RANGE 1000000
using namespace std;

int count[RANGE]; //An array which holds up elements upto the range provided
void countsort(int a[], int n){
  int i;
  int output[RANGE];
  for(i=1;i<RANGE;i++){
    //Loop to make a cumalative sum array of the array count
    count[i]+=count[i-1];
  }
  for(i=0;i<n;i++){
    output[count[a[i]]-1]=a[i];
    //Puts a[i] in its correct place and decreases the count
    count[a[i]]--;
  }
  for(i=0;i<n;i++) cout<<output[i]<<" ";
}

int main(){
  int a[RANGE],n,m=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    count[a[i]]++; //Conts the number of times a[i] occurs
  }
  countsort(a,n);
}
