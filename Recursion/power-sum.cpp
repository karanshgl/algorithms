//Problem : https://www.hackerrank.com/challenges/the-power-sum/problem

#include<iostream>
using namespace std;


int pow(int base, int power){
        if(power==1||power==0)
                return (power==1 ? base : 1);
        if (power%2==0)
                return pow(base, power/2)*pow(base,power/2);
        else
                return pow(base, power/2)*pow(base, power/2 +1);
}


int count=0;
void powerSum(int sum, int power, int be, int curSum){
  if(curSum>sum) return;
  if(curSum==sum){
    ++count;
    return;
  }
  for(int i=be;i<sum;i++){
    int add = pow(i,power);
    powerSum(sum,power,i+1,curSum+add);
  }
}

int main(){
  int base,power;
  cin>>base>>power;
  powerSum(base,power,1,0);
  cout<<count;
}
