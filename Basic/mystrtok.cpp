#include <iostream>

using namespace std;

char *mystrtok(char *input, char delimiter){

        static char *pointer;
        if(input) pointer = input;
        if(!pointer) return NULL;
        char * token = new char [20];
        int i;

        for(i=0; pointer[i]!=delimiter&&pointer[i]!='\0'; i++) {
                token[i]=pointer[i];
        }

        if(pointer[i]=='\0') pointer=NULL;
        else pointer+=i+1;
        token[i]='\0';
        return token;
}

int main(){
        char str[]="Coding blocks is fun";
        char *token=mystrtok(str,' ');
        cout<<token;

        while(token) {
                token=mystrtok(NULL,' ');
                cout<<token;
        }
        return 0;
}
