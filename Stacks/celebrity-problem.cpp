
#include <iostream>
#include<stack>
using namespace std;

bool doesKnow(int x, int y){
	static bool mat[][4] = {
		{0, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};
	return mat[x][y];
}

int celeb(int N){

stack <int> possibleCeleb;

for(int i=0;i<N;i++) possibleCeleb.push(i);

while(possibleCeleb.size()!=1){
  int A = possibleCeleb.top();
  possibleCeleb.pop();
  int B = possibleCeleb.top();
  possibleCeleb.pop();
  if(doesKnow(A,B)) possibleCeleb.push(B);
  else possibleCeleb.push(A);
}

return possibleCeleb.top();

}

int main(){
	int N = 4;
	//Four people viz. 0 1 2 3
	cout << celeb(N)<<endl; // 2 is the celeb
}
