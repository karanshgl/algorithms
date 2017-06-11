
/* A program to sort strings alphabetically and based on their lengths*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <string> vstr;

bool stringCompare(const string &a,const string &b){
        return (a.size()<b.size());
}

void printLoop(vstr &str,int n){
        for(int i=0; i<n; i++) {
                cout<<endl<<str[i];
        }
}

int main(){
        void alpha(vstr &), lengths(vstr &);
        int n,choice;
        vstr strings;
        cout<<"Enter the number of strings ";
        cin>>n;
        strings.resize(n);
        cin.ignore(100,'\n');
        for(int i=0; i<n; i++) {
                getline(cin,strings[i]);
        }
        cout<<"\nSort \n1.Alphabetically\n2.Bases on string lengths";
        cin>>choice;
        switch(choice) {
        case 1: alpha(strings);
                break;
        case 2: lengths(strings);
                break;
        default: cout<<"Invalid Input\n";
                exit(0);
        }
        return 0;
}

void alpha( vstr &str){
        sort(str.begin(),str.end());
        printLoop(str,str.size());
}

void lengths( vstr &str){
        sort(str.begin(),str.end(), stringCompare);
        printLoop(str,str.size());
}
