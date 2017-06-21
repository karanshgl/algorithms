
#include <iostream>

using namespace std;


int abs(int a){
        return (a>0 ? a : -a);
}


int rootFn(int N, int low, int high){
        int mid = (high+low)/2;

        if((mid*mid - N) > 1) return rootFn(N,low,mid-1);
        if(abs(mid*mid -N)<=2*mid) return mid;
        else return rootFn(N,mid+1,high);

}


int main(){

        int N;
        cin>>N;

        cout<<rootFn(N,0,N)<<endl;
        return 0;

}
