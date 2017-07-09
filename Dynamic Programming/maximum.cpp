#include<iostream>

using namespace std;



int profit(int bottles[], int be, int en, int year, int memo[][5]){
  if(be>en) return 0;
  if(memo[be][en]!=0) return memo[be][en];

  int left = bottles[be]*year + profit(bottles,be+1,en,year+1,memo);
  int right = bottles[en]*year + profit(bottles,be,en-1,year+1,memo);
  memo[be][en]=max(left,right);
  return memo[be][en];
}

int main(){
  int bottles[]={2,3,5,1,4};
  int memo[5][5]={};
  cout<<profit(bottles,0,4,1,memo);

}
