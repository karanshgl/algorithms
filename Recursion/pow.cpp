#include <iostream>

using namespace std;

int pow(int base, int power){
        if(power==1||power==0)
                return (power==1 ? base : 1);
        if (power%2==0)
                return pow(base, power/2)*pow(base,power/2);
        else
                return pow(base, power/2)*pow(base, power/2 +1);
}


int main(){
        int a,b;
        cin>>a>>b;
        cout<<pow(a,b);
        return 0;
}
