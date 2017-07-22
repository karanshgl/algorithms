//Codechef : https://www.codechef.com/problems/SANSKAR

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int ll;

bool possible(ll arr[], int be, int en, ll target_sum, ll sum, bool taken[], int k){
	//returns true if it is possible to divide set into subsets summing to sum
	
	if(k==1) return true; //count completed

	if(be>=en) return false;

	if(sum==0) return true;

	if(taken[be] || !arr[be]) return possible(arr,be+1,en,target_sum,sum,taken,k); //if taken continue


	if(target_sum + arr[be]==sum){
		taken[be]=true;
		// we have to take the last element
		return possible(arr,0,en,0,sum,taken,k-1);
	}


		if(target_sum+arr[be]<sum){ //if the element can be added
			taken[be]=true; //first take the element
			if(possible(arr,be+1,en,target_sum+arr[be],sum,taken,k)) return true; //add the element
			taken[be]=false; //dont take the element
		}					
		if(possible(arr,be+1,en,target_sum,sum,taken,k)) return true; //dont add the elemnt

	return false;
}

bool rev (int i,int j) { return (i>j); }


int main(){
	
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll *arr = new ll[n]();

		for(int i=0;i<n;i++) cin>>arr[i];

		ll sum = 0;
		for(int i=0;i<n;i++) sum+=arr[i];
		bool *taken=new bool[n]();

		if(sum%k || k>n){
			cout<<"no"<<endl;
			delete [] taken;
			delete [] arr;
			continue;
		}
		sort(arr,arr+n,rev);
		if(possible(arr,0,n,0,sum/k,taken,k)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;

		delete [] taken;
		delete [] arr;
	}

}

