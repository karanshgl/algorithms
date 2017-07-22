//Codechef : https://www.codechef.com/problems/HORSES

#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;
typedef long long int ll;


int diff(ll arr[], int size){
	ll ans = INT_MAX;
	for(int i=1;i<size;i++){
		ans=min(ans,arr[i]-arr[i-1]);
	}

	return ans;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll *arr=new ll[n]();
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		cout<<diff(arr,n)<<endl;
		delete [] arr;

	}
}