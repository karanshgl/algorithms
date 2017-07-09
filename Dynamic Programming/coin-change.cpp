#include<iostream>

using namespace std;

int arr[]={1,3,5,6};
int n=4;
const int inf = 1000000 ;

int coins(int sum, int*memo){
  if(sum==0) return memo[sum] = 0;
  if(sum<0) return inf;

  if(memo[sum]!=-1) return memo[sum];

  int res =inf;
  for(int i=0;i<n;i++){
    int rem = coins(sum - arr[i],memo);
    int curAns = rem + 1;
    res = min(res, curAns);
  }
  return memo[sum] = res;
}

int change(int val){
  int *memo = new int[val+1]();
  for(int i=1;i<=val;i++) memo[i]=inf;

  for(int i=1;i<=val;i++){
    for(int j=0;j<n && arr[j]<=i;j++){
      int coin = memo[i-arr[j]] + 1;
      memo[i] = min(memo[i],coin);
    }
  }
  return memo[val];
}

int main(){
  int val;
  cin>>val;
  int *memo = new int [val+1];
  for(int i=0;i<=val;i++) memo[i] = -1;

  //memset(memo, 4* (val+1), -1); cstring
  cout<<change(val);
  delete [] memo;
}
