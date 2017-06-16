#include <iostream>

using namespace std;
const int N = 9;
const int n = 3;

void printBoard(int board [][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++) cout<<board[i][j]<<" ";
    cout<<endl;
  }
}

bool canPlace(int board[][N], int x, int y, int num){

        for(int i=0; i<N; i++) {
                if(num==board[x][i]) return false;
        }

        for(int i=0; i<N; i++) {
                if(num==board[i][y]) return false;
        }

        int rBox=x/n, cBox=y/n;
        rBox*=n;
        cBox*=n;

        for(int i=rBox; i<rBox+n; i++) {
                for(int j=cBox; j<cBox+n; j++) {
                        if(num==board[i][j]) return false;
                }
        }

        return true;
}

bool solveSudoku(int board[][N], int x, int y){

        if(x==N) return true;

        if(y==N) return solveSudoku(board,x+1,0);

        if(!board[x][y]) {
                for(int j=1; j<10; j++) {
                        if(canPlace(board,x,y,j)) {
                                board[x][y]=j;
                                if(solveSudoku(board,x,y+1)) return true;
                                board[x][y]=0;
                        }
                }
        }

        else return solveSudoku(board,x,y+1);

        return false;
}


int main(){

      int board[N][N]={};

      if(solveSudoku(board,0,0)) printBoard(board);
      else cout<<"Not Possible";
        return 0;
}
