#include<iostream>

using namespace std;
int cnt;
void subsequence(char str[],int a ,char output[], int i){
  if(str[a]=='\0')
    {
      output[i]='\0';
      ++cnt;
      cout<<cnt<< " "<<output<<endl;
      return;
    }
  else{
    subsequence(str,a+1,output,i);
    output[i]=str[a];
    subsequence(str,a+1,output,i+1);
  }
}

int main(){
  char str[100], output[100]="";
  cin>>str;
  cout<<endl;
  subsequence(str,0,output,0);
  return 0;
}
