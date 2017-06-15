#include <iostream>

using namespace std;

char output[]="";
void printCodes(char num[], int i, int a){
        if(num[i]=='\0') {
                output[a]='\0';
                cout<<output<<endl;
                return;
        }
        int dig = num[i] - 48;
        char c = 'A' + dig - 1;
        output[a]=c;
        printCodes(num,i+1,a+1);
        if(num[i+1]=='\0') return;
        int nextDig = num[i+1] - 48;
        int pair = 10*dig + nextDig;
        if(pair>26) return;
        c = 'A' + pair -1;
        output[a]=c;
        printCodes(num, i+2,a+1);
}

int main(){
        char num[100];
        cin>>num;
        printCodes(num,0,0);
        return 0;
}
