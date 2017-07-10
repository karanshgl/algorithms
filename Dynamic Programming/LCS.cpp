#include<iostream>
#include<string>

using namespace std;

int len(char str[]){
  int i=0;
  while(str[i]!='\0') i++;
  return i;
}


string lcs(char str1[], char str2[]){

  int row = len(str1);
  int col =  len(str2);
  int index = 0;
  string ans;
  string ** strMatrix = new string*[row];
  for(int i=0;i<row;i++) strMatrix[i] = new string[col]();
  
  for(int i=0;i<row;i++){
    for(int j=index;j<col;j++){
      if(i-1>=0) strMatrix[i][j] = strMatrix[i-1][j];
      //If there is a substring on top, copy that
      if(str1[i]==str2[j]){
        //If there is there is another common element
        strMatrix[i][j].push_back(str1[i]);
        index = j + 1;
        for(int k=index;k<col;k++) strMatrix[i][k] = strMatrix[i][j];
        //Copy the same data on the rest of the matrix
        ans = strMatrix[i][j];
        //ans stores the answer
        break;
      }
    }
  }

for(int i=0;i<row;i++) delete [] strMatrix[i];
delete [] strMatrix;

return ans;
}

int main(){
  char a[]="AGGTAB";
  char b[]="GXTXAYB";

  cout<<lcs(b,a);
}
