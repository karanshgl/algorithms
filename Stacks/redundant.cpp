#include<iostream>
#include<stack>

using namespace std;

bool checkop(char c){
  if(c=='+'||c=='-'||c=='*'||c=='/') return true;
  return false;
}


int redPara(char *str){
  int cnt=0;
  stack <char> st;
  bool op=false;
  for(int i=0;str[i]!='\0';i++){
    op=false;
    if(checkop(str[i])||str[i]=='(') st.push(str[i]);
    if(str[i]==')'){
      while(st.empty()==false && st.top()!='('){
        if(checkop(st.top())) op=true;
        st.pop();
      }
      st.pop();
      if(!op) cnt++;
    }
  }
  return cnt;
}


int main(){
  char str[100];
  cin>>str;
  cout<<redPara(str)<<endl;
}
