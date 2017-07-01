#include <iostream>
using namespace std;
void input2D(int mat[][10], int m, int n){
        for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                        cin >> mat[i][j];
                }
        }
}


void printSpiral(int mat[][10], int m, int n){
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while(left <= right || top <= bottom) {
                if(top <= bottom) {
                  //Prints the top row left ro right
                        for(int i = left; i <= right; ++i) {
                                cout << mat[top][i]<<", ";
                        }
                        ++top;
                }

                if (left <= right) {
                  //Prints the right col top to down
                        for(int i = top; i <= bottom; ++i) {
                                cout << mat[i][right]<<", ";
                        }
                        --right;
                }

                if (top <= bottom) {
                  //Prints the bottom row righ to left
                        for(int col = right; col >= left; --col) {
                                cout << mat[bottom][col]<<", ";
                        }
                        --bottom;
                }

                if (left <= right) {
                  //Prints the left col bottom to top
                        for(int row = bottom; row >= top; --row) {
                                cout << mat[row][left]<<", ";
                        }
                        left++;
                }
        }
}



int main(){
        int mat[10][10];
        int m, n;
        cin >> m >> n;
        input2D(mat, m, n);

        printSpiral(mat, m, n);
        cout<<"END"<<endl;
        return 0;
}
