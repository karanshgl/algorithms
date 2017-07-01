#include <iostream>

using namespace std;

int len(char *str){
  //A function which returns the length of a char array
  int i=0;
  while(str[i]!='\0') i++;
  return i;
}

char *mystrtok(char *input, char delimiter){
  //A function which returns a char pointer to the token i.e. tokenizes the cstring
        static char *pointer;
        //Static pointer will remember its position throughout the program
        if(input) pointer = input;
        if(!pointer) return NULL; //If pointer is NULL
        char * token = new char [len(pointer)+1]; //New memory has to be allocated
        int i;
        for(i=0; pointer[i]!=delimiter&&pointer[i]!='\0'; i++) {
          //loop which copies the data from the input string to the token
                token[i]=pointer[i];
        }

        if(pointer[i]=='\0') pointer=NULL;
        else pointer+=i+1; //Pointer goes to the next ocurrance of the delimiter
        token[i]='\0';
        return token;
}

int main(){
        char str[]="This is my string";
        char *token=mystrtok(str,' ');
        cout<<token;

        while(token) {
                token=mystrtok(NULL,' ');
                cout<<token;
        }
        return 0;
}
