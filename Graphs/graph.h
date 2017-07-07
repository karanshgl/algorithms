#include<iostream>
#include<vector>
#include<queue>

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
  typedef vector<int> vi;

  int nV;
  int nE;
  vi *adjList;


    void dfs_helper(int src, bool visited[]){

      visited[src] = true; //Vertex is visited
      cout<<src<<" ";
      for(int i=0;i<adjList[src].size();i++){
        int neighbor = adjList[src][i];
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

  void addEdge(int x, int y, bool directional = false){
    adjList[x].push_back(y);
    ++nE;
    if(directional) return;

    adjList[y].push_back(x);
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
        int neighbor = adjList[cur][i];
        if(visited[neighbor]==false){
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    delete [] visited;
  }

  int shortestDistance(int src, int dest){
    bool* visited = new bool[nV+1]();
    int* dist = new int[nV+1]();
    queue<int> q;
    vi vist;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
      int cur=q.front();
      q.pop();

    //  cout<<cur<<" ";

      for(int i=0;i<adjList[cur].size();i++){
        int neighbor = adjList[cur][i];
        if(visited[neighbor]==false){
          visited[neighbor] = true;
          dist[neighbor] = dist[cur] + 1;
          q.push(neighbor);
        }
      }
    }



    int ans = dist[dest];

    delete [] dist;
    delete [] visited;
    return ans;
  }

  vi shortestPath(int src, int dest){
    bool* visited = new bool[nV+1]();
    //int* dist = new int[nV+1]();
    int* parent = new int[nV+1]();
    vi path;
    queue<int> q;
    vi vist;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
      int cur=q.front();
      q.pop();

    //  cout<<cur<<" ";

      for(int i=0;i<adjList[cur].size();i++){
        int neighbor = adjList[cur][i];
        if(visited[neighbor]==false){
          visited[neighbor] = true;
          parent[neighbor] = cur;
      //    dist[neighbor] = dist[cur] + 1;
          q.push(neighbor);
        }
      }
    }

    int it = dest;

    while(it!=src){
      path.push_back(it);
      it=parent[it];
    }
    path.push_back(it);

    //int ans = dist[dest];

    delete [] parent;
    delete [] visited;
    return path;
  }


  vector <int> topologicalSort(){
    //calculate inDegree
    int* inDegree = new int[nV+1]();
    for(int ver = 1; ver<=nV; ver++){
      for(int i=0;i<adjList[ver].size();i++){
        int neighbor = adjList[ver][i];
        ++inDegree[neighbor];
      }
    }

    queue <int> q;
    //search for potential candidates

    for(int i=1; i <=nV; ++i){
      if(inDegree[i]==0) q.push(i);
    }

    vector<int> ans;
    while(q.empty()==false){
      int cur=q.front();
      q.pop();
      ans.push_back(cur);
      for(int i=0;i<adjList[cur].size();i++){
        int neighbor = adjList[cur][i];
        --inDegree[neighbor];
        if(inDegree[neighbor]==0) q.push(neighbor);
      }
    }

    return ans;
  }

};
