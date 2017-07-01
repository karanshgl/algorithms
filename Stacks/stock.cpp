#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector <int> stkSpan(int prices[], int n){
  vector<int> span(n);
  	stack<int> prevGreater;		//stores index

  	for(int i = 0; i < n; ++i){
  		while(prevGreater.empty() == false){
  			int idx = prevGreater.top();
  			//remove all useless elements---Useless because they will not be encountered in the calculation
  			//of span of upcoming stock days
  			if (prices[idx] < prices[i]){
  				prevGreater.pop();
  			}
  			else {
  				break;
  			}
  		}
  		int best = prevGreater.empty() ? 0 : prevGreater.top();
  		span[i] = i - best;
  		prevGreater.push(i);
  	}

  	return span;
}



int main(){
int stocks[1000],n;
cin>>n;
for(int i=0;i<n;i++) cin>>stocks[i];

vector<int> days = stkSpan(stocks,n);

for(int i=0;i<n;i++) cout<<days[i]<<" ";


return 0;
}
