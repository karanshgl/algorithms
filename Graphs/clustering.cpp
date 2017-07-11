#include<iostream>

using namespace std;

int M,N;
char mat[10][10];

void input(char mat[][10],int M, int N){
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++) cin>>mat[i][j];
  }
}


void dfs(int x, int y, char mat[][10], bool visited[][10]){
    int row[] = {-1,-1,-1,0,1,1,1,0};
    int col[] = {-1,0,1,1,1,0,-1,-1};
    visited[x][y] = true;
    for(int i=0;i<8;i++){
      int curRow = x + row[i];
      int curCol = y + col[i];
      if(curCol<N && curRow<M && curRow>=0 && curCol>=0){
        if(!visited[curRow][curCol] && mat[curRow][curCol]=='.'){
          dfs(curRow,curCol,mat,visited);
        }
      }
  }
}


int clustering(char mat[][10]){
  bool visited[10][10]={};

  int numCC=0;
  for(int r=0;r<M;++r){
    for(int c=0;c<N;++c){
      if(!visited[r][c] && mat[r][c]!='#'){
        ++numCC;
        dfs(r,c,mat,visited);
      }
    }
  }
  return numCC;
}


int main(){
  cin>>M>>N;
  input(mat,M,N);
  cout<<clustering(mat);
}
