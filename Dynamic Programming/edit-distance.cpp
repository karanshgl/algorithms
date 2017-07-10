#include<iostream>

using namespace std;


int len(char str[]){
  int i=0;
  while(str[i]!='\0') i++;
  return i;
}

int lcs(char a[], char b[]){
//finding the length of the longest substring

    int row = len(a);
    int col = len(b);

    int **lengthMatrix = new int*[row+1];
    for(int i=0;i<=row;i++) lengthMatrix[i] = new int[col+1]();

    for(int i=1;i<=row;i++){
      for(int j=1;j<=col;j++){

        if(a[i-1]==b[j-1]){
          /* If a common element is found, check the left diagonal
          i.e. vale of longest substring before encountering the common element */
           lengthMatrix[i][j] = 1 + lengthMatrix[i-1][j-1];
        }
        else lengthMatrix[i][j] = max(lengthMatrix[i-1][j], lengthMatrix[i][j-1]); //take the maximum lcs as usual
      }

    }
    int ans = lengthMatrix[row][col];
    for(int i=0;i<=row;i++) delete [] lengthMatrix[i];
    delete [] lengthMatrix;
    return ans;
}


int numberOperations(char a[], char b[]){

  int intersection = lcs(a,b);
  return max(len(a),len(b)) -intersection;
}


int main(){
  char a[]="saturday";
  char b[]="sunday";
  cout<<numberOperations(a,b);
}
