#include <iostream>

using namespace std;

bool pal(char a[], int n, int last){
  //function which checks if a string is a palindrome
        if(a[2*n]=='\0'||a[2*n+1]=='\0') return true;

        if(a[n]==a[last-n]) return pal(a,n+1,last);

        return false;
}

int main(){

        char a[100];
        cin>>a;
        int l=0;
        while(a[l]!='\0') l++;
        if(pal(a,0,l-1)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        return 0;
}
