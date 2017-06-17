
#include <iostream>

using namespace std;

const double epsilon = 0.0001;

double abs(double a){
        return (a>0 ? a : -a);
}


double rootFn(double N, double p, double low, double high){
        double mid = (high+low)/2;

        if(abs(high-low)<epsilon) return high;

        if((mid*mid - N) > epsilon) return rootFn(N,p,low,mid-p);
        if(abs(mid*mid -N) < epsilon) return mid;
        else return rootFn(N,p,mid+p,high);

}


int main(){

        double N, precision = 0.001;
        cin>>N;

        cout<<rootFn(N,precision,0,N)<<endl;
        return 0;

}
