#include<iostream>
using namespace std;

int knapsack(int weight[], int value[], int n, int total){
//A function that returns the maximum value we can get
  int **knapMatrix = new int *[n];
  for(int i=0;i<n;i++) knapMatrix[i] = new int[total+1];

  for(int i=0;i<n;i++){
    for(int j=0;j<=total;j++){
      int prev = (i-1>=0 && j - weight[i]>=0? knapMatrix[i-1][j-weight[i]]:0);
      //prev value for the remaining max weight
      int above = (i-1>=0? knapMatrix[i-1][j]:0);
      //value caluculated by the above set of weights
      if(j - weight[i]>=0) knapMatrix[i][j] = max(value[i] + prev, above); //if we can take the weight[i]
      else knapMatrix[i][j] = above; //if we can't take the weight[i]
    }
  }
  
  int ans =knapMatrix[n-1][total];
  for(int i=0;i<n;i++) delete [] knapMatrix[i];
  delete [] knapMatrix;
  return ans;
}


int main(){
  int v[]={1,4,5,7};
  int w[]={1,3,4,5};
  cout<<knapsack(w,v,4,7);
}
