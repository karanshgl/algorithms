#include <iostream>
#include <string>

using namespace std;



int count(string str){
	int ans=0;
	int greater=0;
	int lesser=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='<'){
			lesser=0;
			greater++;
			ans=max(ans,greater);
		}
		else if(str[i]=='>'){
			greater=0;
			lesser++;
			ans=max(ans,lesser);
		}
	}
	return ans;
}


int main(){
	int t;
	string str;
	cin>>t;
	cin.ignore(100,'\n');
	while(t--){
		getline(cin,str);
		cout<<count(str)+1<<endl;
	}
}