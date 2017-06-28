#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector <int> stkSpan(int stocks[], int n){
  vector <int> days;
  stack <int> prevGreater;
  prevGreater.push(0);
  for(int i=0;i<n;i++){
    while(prevGreater.empty()==false && stocks[i]>stocks[prevGreater.top()]) prevGreater.pop();
    days.push_back(i-prevGreater.top());
    prevGreater.push(i);
  }
return days;
}



int main(){
int stocks[1000],n;
cin>>n;
for(int i=0;i<n;i++) cin>>stocks[i];

vector<int> days = stkSpan(stocks,n);

for(int i=0;i<n;i++) cout<<days[i]<<" ";


return 0;
}
