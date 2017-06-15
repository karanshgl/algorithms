#include <iostream>
#include <string>

using namespace std;
string array[]={".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char output[]="";
void generateCode(char num[],int i, int a){
        if(num[i]=='\0') {
                output[a]='\0';
                cout<<output<<endl;
                return;
        }
        int j;
        string it=array[num[i]-'0'-1];
        for(j=0; j<it.size(); j++) {
                output[a]=it[j];
                generateCode(num,i+1,a+1);
        }
}

int main(){
        char num[100];
        cin>>num; //Enter a number
        generateCode(num,0,0);
        return 0;
}
