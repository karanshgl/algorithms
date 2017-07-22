//Problem : https://www.codechef.com/problems/LAPIN

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map <char,int> si;

bool isLapin(string str){
//returns true if Lapindrome

	si m; //map

	for(int i=0;i<str.size()/2;i++) ++m[str[i]]; //increment frequency count of letters to the left of center

	int mid = ((str.size()%2)==0? str.size()/2 : str.size()/2 + 1); //initial the starting point of the right half

	for(int i=mid;i<str.size();i++) --m[str[i]]; //decrement frequency count of letters to the right of center

	
	for(si::iterator it=m.begin();it!=m.end();it++){
		if(it->second!=0) return false;	//If any letter has non-zero net frequency it is not a lapin
	}

	return true;
}

int main(){
	int t;
	string str;
	cin>>t;
	while(t--){
		cin>>str;
		if(isLapin(str)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}