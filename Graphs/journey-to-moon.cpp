//Hackerrank question https://www.hackerrank.com/challenges/journey-to-the-moon

#include<iostream>
#include<list>
using namespace std;

class Graph{
  //Made the graph
  typedef list<int>::iterator lit;
  int nE;
public:
  int nV;
  list<int>* adjList;
  Graph(int N){
    nV = N;
    nE = 0;
    adjList = new list<int>[N];
  }

  ~Graph(){
    delete [] adjList;
  }

  void addEdge(int src, int dest){
    //Adds egde to graph
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
  }

  void dfs(int src, bool *visit, int &x){
    //finds connected component;
    visit[src]= true;
    ++x;
    for(lit neighbor = adjList[src].begin();neighbor!=adjList[src].end();++neighbor){
      if(visit[*neighbor]== false) dfs(*neighbor,visit,x);
    }
  }
};

long long int findNum(int arr[], int size, long long int N){
  //returns the number of ways to select people
  long long int total = N*(N-1)/2;

  for(int i=0; i<size; i++){
    total -= (arr[i]*(arr[i]-1)/2);
  }
  return total;
}


int main(){
  int N;
  int x,y; //tracks edge
  int P;

  cin>>N>>P;
  Graph G(N);
  for(int i=0;i<P;++i){
    cin>>x>>y;
    G.addEdge(x,y);
  }
  int numCC=0;
  bool *visit=new bool[N]();
  int *numComp = new int[N+1]();
  for(int i=0;i<N;i++ ){
    if(visit[i]==false){
      G.dfs(i,visit,numComp[numCC]);
      numCC++;
    }
  }

  //for(int i=0;i<numCC;i++) cout<<numComp[i]<<" ";
cout<<findNum(numComp,numCC,N)<<endl;
}
