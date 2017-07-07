#include<iostream>
#include "graph.h"

using namespace std;

int main(){
  Graph G(36);
  int snakeLadder[37]={};
  //Snakes
  snakeLadder[2] = 15;
  snakeLadder[5] = 7;
  snakeLadder[9] = 27;
  snakeLadder[25] = 35;
  snakeLadder[18] = 29;
  //Snakes
  snakeLadder[34] = 12;
  snakeLadder[32] = 30;
  snakeLadder[24] = 16;
  snakeLadder[17] = 4;
  snakeLadder[20] = 6;
  for(int i=1;i<=36;i++){
    for(int j=i+1;j<=i+6 && j<=36;j++){
      G.addEdge(i,j, true);
    }
    if(snakeLadder[i]){
      G.addEdge(i,snakeLadder[i],true);
    }
  }

vector<int> v = G.shortestPath(1,36);
printContainer(v.begin(),v.end());
}
