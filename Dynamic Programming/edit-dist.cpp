#include<iostream>
#include<cstring>
using namespace std;

int editDist(char str1[], char str2[], int len1, int len2){

  int memo[len1+1][len2+1]={};

  for(int i=0;i<=len1;i++){
    for(int j=0;j<=len2;j++){
      if(i==0) memo[i][j]=j;
      else if(j==0) memo[i][j]=i;

      else if(str1[i-1]==str2[j-1]) memo[i][j] = memo[i-1][j-1];

      else {
        memo[i][j] = 1 + min(
        min(
          memo[i][j-1],
          memo[i-1][j-1]
        ),
        memo[i-1][j]
      );
    }
  }
}
return memo[len1][len2];
}

int main(){
  char str1[100], str2[100];
  cin>>str1>>str2;
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  cout<<editDist(str1,str2,len1,len2);
}
