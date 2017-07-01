//A program to print an anticlockwise spiral of a matrix

#include <iostream>
using namespace std;
void input2D(int mat[][10], int m, int n){
  //Function to take an input
        for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                        cin >> mat[i][j];
                }
        }
}


void printSpiral(int mat[][10], int m, int n){
  //A function which prints the spiral
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while(left <= right || top <= bottom) {
                if (left <= right) {
                  //Prints the left most column top to bottom
                        for(int i = top; i <= bottom; ++i) {
                                cout << mat[i][left]<<", ";
                        }
                        left++; //Shifts the left row by 1
                }
                if (top <= bottom) {
                  //Prints the bottom row from left to right
                        for(int col = left; col <= right; ++col) {
                                cout << mat[bottom][col]<<", ";
                        }
                        --bottom; //Shifts the bottom up by 1
                }

                if (left <= right) {
                  //Prints the right most column bottom to top
                        for(int row = bottom; row >= top; --row) {
                                cout << mat[row][right]<<", ";
                        }
                        right--; //SHifts the right col to left by 1
                }
                if(top <= bottom) {
                  //prints the top most row right to left
                        for(int i = right; i >=left; --i) {
                                cout << mat[top][i]<<", ";
                        }
                        ++top; //Shifts top down by 1
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
