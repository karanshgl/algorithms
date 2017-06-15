#include <iostream>
#define N 4
using namespace std;


void printSol(bool sol[][N]){
        cout<<"The Solution is"<<endl;
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) cout<<sol[i][j]<<" ";
                cout<<endl;
        }
}

bool canMove(bool maze[][N], int x, int y){
        if(x>=0 && x<N && y>=0 && y<N && maze[x][y]) return true;
        return false;
}

bool move(bool maze[][N], int x, int y, bool sol[][N]){

        if(x==N-1&&y==N-1) {
                sol[x][y]=1;
                return true;
        }

        if(canMove(maze,x,y)) {
                sol[x][y]=1;

                if(move(maze,x+1,y,sol)) return true;

                if(move(maze,x,y+1,sol)) return true;

                sol[x][y]=0;
        }
        return false;
}


int main(){
        bool maze[N][N], sol[N][N]={};
        cout<<"Enter the maze of size "<<N<<endl;
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) cin>>maze[i][j];
        }
        cout<<endl;
        if(move(maze,0,0,sol)) printSol(sol);
        else cout<<"Not Possible"<<endl;
        return 0;
}
