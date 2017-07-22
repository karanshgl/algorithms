//Codechef : https://www.codechef.com/problems/JOHNY

#include<iostream>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int low, int high, int element){
	if(low>high) return -1;

	int mid=(low+high)/2;

	if(arr[mid]<element) return binarySearch(arr,mid+1,high,element);
	else if(arr[mid]>element) return binarySearch(arr,low,mid,element);
	else return mid;
}

int main(){
	int t,n,uj;
	cin>>t;

	while(t--){

		cin>>n;
		int *arr=new int[n]();
		for(int i=0;i<n;i++) cin>>arr[i];
		cin>>uj;
		uj=arr[uj-1];
		sort(arr,arr+n);
		cout<<binarySearch(arr,0,n-1,uj)+1<<endl;
		delete [] arr;
	}
}