#include <iostream>

#define N 4

using namespace std;

void print(bool board[][N]){
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) cout<<board[i][j]<<" ";
                cout<<endl;
        }
}

bool checkPlace(bool board[][N],int x, int y){

        for(int i=0; i<x; i++) {
                if(board[i][y]==1) return false;
        }

        for(int i=x-1,  j=y-1; i>=0&&j>=0; i--,j--) {
                if(board[i][j]==1) return false;
        }

        for(int i=x-1,  j=y+1; i>=0&&j<N; i--,j++) {
                if(board[i][j]==1) return false;
        }

        return true;
}

bool placeQueen(bool board[][N], int r){

  if(r>=N) return true;

  for(int i=0;i<N;i++){
    if(checkPlace(board,r,i)){
      board[r][i]=1;
      if(placeQueen(board,r+1)) return true;
      board[r][i]=0;
    }
  }
  return false;
}


int main(){
  bool board[N][N]={};
  if(placeQueen(board,0)) print(board);
  else cout<<"Not Possible"<<endl;
  return 0;
}
