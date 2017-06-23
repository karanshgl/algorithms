#include<iostream>

using namespace std;
int cnt,target_sum;
void subsequence(int str[],int a ,int n,int sum){
  if(a==n) return;
  if(sum>target_sum) return;
  if(sum==target_sum){
    cnt++;
    return;
  }
  else{
    subsequence(str,a,output,sum+str[a]);
    subsequence(str,a+1,output,sum);
  }
}

int main(){
  int str[100],n;
  cin>>target_sum;
  cin>>n;
  for(int i=0;i<n;i++) cin>>str[i];
  subsequence(str,0,n,0);
  return 0;
}
