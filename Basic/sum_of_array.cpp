//Two numbers are stored in two interger arrays, A program to add these two integers and save in a new array

#include<iostream>

using namespace std;

int sum[1000];
void shift(int a[], int s, int n){
  //A function that shifts an array by s distance to the right
  while(n--){
    a[n+s]=a[n];
  }
  for(int i=0;i<s;i++) a[i]=0; //makes the left over space 0
}

int add(int a[], int b[], int n){
  //A function which adds the two arrays, n is the size of the larger array
  int carry=0;
  for(int i=n-1;i>=0;i--){
    sum[i] = a[i] + b[i] + carry;
    carry = sum[i]/10; //Calculates the carry over
    sum[i]%=10; //Puts the sum into the array
  }
  if(carry){
    shift(sum,1,n); //The carry over would require space
    sum[0]=carry;
    return 1; //return of 1 signifies that the size of the array has increased
  }
  return 0;
}



int main(){
  int n,m,a[1000],b[1000];
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  cin>>m;
  for(int i=0;i<m;i++) cin>>b[i];

  if(m>n) shift(a,m-n, n);
  else shift(b, n-m, m);
  m=max(m,n);

  if(add(a,b,m)) m++;

  for(int i=0;i<m;i++) cout<<sum[i]<<", ";
  cout<<"END"<<endl;

  return 0;
}
