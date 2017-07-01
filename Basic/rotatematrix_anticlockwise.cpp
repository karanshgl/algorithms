#include <iostream>

using namespace std;


void rotate(int arr[][1000], int m){
  //A function to rotate a matrix anticlockwise
        int rot[m][m];
        int r=0,c=0;
        for(int i=m-1; i>=0; i--) {
                for(int j=0; j<m; j++) {
                        rot[r][c++]=arr[j][i];
                }
                r++;
        }
        for(int i=0; i<m; i++) {
                for(int j=0; j<m; j++) cout<<rot[i][j]<< " ";
                cout<<endl;
        }

}


int main(){
        int m;
        int arr[1000][1000];
        cin>>m;
        for(int i=0; i<m; i++) {
                for(int j=0; j<m; j++) cin>>arr[i][j];
        }

        rotate(arr,m);
        return 0;

}
