#include <iostream>
#include <string>
#include <locale> 
#include <cstring>

using namespace std;


void printName(char *str){
	int iPointer=0;
	string ans;
	locale loc;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==' '){
			ans.push_back(toupper(str[iPointer],loc));
			ans.push_back('.');
			ans.push_back(' ');
			iPointer=i+1;
		}
	}
	ans.push_back(toupper(str[iPointer],loc));
	for(int i=iPointer+1;str[i]!='\0';i++) ans.push_back(tolower(str[i],loc));
	cout<<ans<<endl;
}


int main(){
	int t;
	char str[1000000];
	cin>>t;
	cin.ignore(100,'\n');

	while(t--){
		cin.getline(str,1000000);
		printName(str);
	}

}