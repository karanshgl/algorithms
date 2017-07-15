//Problem :  https://www.hackerrank.com/challenges/recursive-digit-sum

#include<iostream>
#include <string>
using namespace std;

string digitSum(string num, int k=1){
  string res;
  int sum=0;
  while(k--){
    for(int i=0;i<num.size();i++){
      sum+=num[i]-'0';
      if(sum>9){
        res.push_back((sum/10) + '0');
        sum=sum%10;
      }
    }
  }
  res.push_back(sum+'0');
  return res;
}

int superDigit(string digit){
  //returns the super digit
  if(digit.size()==1) return (digit[0]-'0');
  return superDigit(digitSum(digit));
}

int main(){
  string num;
  int k;
  cin>>num>>k;

  cout<<superDigit(digitSum(num,k))<<endl;
}
