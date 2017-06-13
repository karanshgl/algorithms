#include <iostream>

using namespace std;

void tower(char S, char D, char H, int n){
        if(n==0)
                return;
        tower(S,H,D,n-1);
        cout<<S<<" -> "<<D<<endl;
        tower(H,D,S,n-1);
}

int main(){
  int n;
  cin>>n;
  tower('S','D', 'H',n); //S means the Source | D means the destination | H means the Helper
  return 0;
}
