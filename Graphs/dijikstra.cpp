#include<iostream>
#include<queue>
#include<list>

using namespace std;


class Vertex{
public:
  int id;
  int wt;
  Vertex(int s, int w){
    id = s;
    wt = w;
  }

  bool operator < (const Vertex A) const{
    return wt < A.wt;
  }
};

class Graph{
  list <Vertex> *adjList;
  int nV;
  int nE;
public:
  Graph(int n){
    nV = n;
    nE = 0;
    adjList =  new list<Vertex> [nV+1];
  }

  ~Graph(){
    delete [] adjList;
  }


  void addEdge(int src, int dest, int wt){
    adjList[src].push_back(Vertex(dest,wt));
    ++nE;

    adjList[dest].push_back(Vertex(src,wt));
    ++nE;
  }

  int dijikstra(int src, int dest){
    int *dist = new int[nV+1];
    //initially set to infinity
    const int inf = (int)1e7;
    for(int i=1;i<=nV;i++) dist[i]= inf;

    priority_queue<Vertex> q;
    q.push(Vertex(src,0)); //distance of src from src is 0

    while(q.empty()==false){
      Vertex curVer = q.top();
      q.pop();
      dist[curVer.id] = min(curVer.wt, dist[curVer.id]); 

      for(list<Vertex>::iterator it = adjList[curVer.id].begin(); it != adjList[curVer.id].end(); ++it){
        Vertex neighbour = *it;
        int distFromSrc = neighbour.wt + curVer.wt; //distance of enighbour from src = wt of neighbour + wt of reference vertex
        if(distFromSrc < dist[neighbour.id]) q.push(Vertex(neighbour.id,distFromSrc)); //minimum distance
      }
    }
    int ans = dist[dest];
    delete [] dist;
    return ans;
  }
};


int main(){

  Graph G(7);
  G.addEdge(1,2,10);
  G.addEdge(1,3,80);
  G.addEdge(2,5,20);
  G.addEdge(2,3,6);
  G.addEdge(5,7,10);
  G.addEdge(5,6,50);
  G.addEdge(7,6,10);
  G.addEdge(3,4,70);
  cout<<G.dijikstra(1,4);
}
