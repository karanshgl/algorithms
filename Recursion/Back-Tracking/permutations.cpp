#include<iostream>

using namespace std;

void swap(int &x, int &y){
  int temp;
  temp=y; y=x; x=temp;
}

void permutation(char str[], int i){
  if(str[i]=='\0'){
    cout<<str<<endl;
    return;
  }

  for(int j=i;str[j]!='\0';j++){
    swap(str[i], str[j]);
    permutation(str,i+1);
    swap(str[i],str[j]);
  }

}

int main(){
  char str[100];
  cin>>str;
  permutation(str,0);
  return 0;

}
