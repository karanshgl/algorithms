#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

template<typename T>
void printContainer(T be, T en){
  while(be!=en){
    cout<<*be<<" ";
    ++be;
  }
  cout<<endl;
}



class Graph{
  typedef vector<pair<int,int> > vi;

  int nV;
  int nE;
  vi *adjList;


    void dfs_helper(int src, bool visited[]){

      visited[src] = true; //Vertex is visited
      cout<<src<<" ";
      for(int i=0;i<adjList[src].size();i++){
        int neighbor = adjList[src][i].first;
        //Check the neighbour if it is visited
        if(visited[neighbor]==false){
          dfs_helper(neighbor, visited);
        }
      }
    }


public:
  Graph(int n){
    nV = n;
    nE = 0;
    adjList = new vi[nV+1]; //dyanmic memory allocation
  }

  ~Graph(){
    delete [] adjList;
  }

  void addEdge(int x, int y, int weight ,bool directional = false){
    adjList[x].push_back(make_pair(y,weight));
    ++nE;
    if(directional) return;

    adjList[y].push_back(make_pair(x,weight));
    ++nE;
  }

  void dfs(int src){
    bool* visited = new bool[nV]();

    dfs_helper(src,visited);
    delete [] visited;
  }

  void print(){
    bool* visited = new bool[nV+1]();
  //  printAll(1,visited);
    for(int i=1;i<=nV;i++){
      if(visited[i]==false){
        dfs_helper(i,visited);
        cout<<endl;
      }
    }
    delete [] visited;
  }

  void bfs(int src){
    bool* visited = new bool[nV+1]();
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
      int cur=q.front();
      q.pop();

      cout<<cur<<" ";

      for(int i=0;i<adjList[cur].size();i++){
        int neighbor = adjList[cur][i].first;
        if(visited[neighbor]==false){
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    delete [] visited;
  }




};
