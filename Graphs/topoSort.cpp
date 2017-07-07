#include "graph.h"
#include<iostream>

using namespace std;

int main(){
  Graph G(6);
  G.addEdge(6,4,true);
  G.addEdge(6,3,true);
  G.addEdge(4,5,true);
  G.addEdge(3,5,true);
  G.addEdge(5,1,true);
  G.addEdge(5,2,true);

  vector<int> v = G.topologicalSort();
  printContainer(v.begin(),v.end());
}
