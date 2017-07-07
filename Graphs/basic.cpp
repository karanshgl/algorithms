#include<iostream>
#include "graph.h"

using namespace std;

int main(){
  Graph G(8);

  G.addEdge(1,2);
  G.addEdge(1,3);
  G.addEdge(3,4);
  G.addEdge(2,5);
  G.addEdge(5,6);
  G.addEdge(6,7);
  G.addEdge(7,5);
  //G.addEdge(8,8);
  vector<int> v = G.shortestPath(4,7);
  //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
  printContainer(v.begin(),v.end());
}
