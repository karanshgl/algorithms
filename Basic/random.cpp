#include <iostream>
#include <iomanip>  
using namespace std;

int main(){
	double t,U,V,X;
	cin>>t;
	while(t--){
		cin>>U>>V>>X;
		double ans = 1.0*X/(U+V);
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
}