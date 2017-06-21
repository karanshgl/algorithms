#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector <int> ans;
void Fn(vector<int> &v1, vector <int> &v2){
  int i=0,j=0;
  while(i<v1.size()&&j<v2.size()){
    if(v1[i]<v2[j]) i++;
    else if(v2[j]<v1[i]) j++;
    else {ans.push_back(v1[i]); i++; j++;}
  }
}

int main(){

  vector<int> v1,v2;
  int n,i;
  cin>>n;
  v1.resize(n);
  v2.resize(n);
  for(int i=0;i<n;i++) cin>>v1[i];
  for(int i=0;i<n;i++) cin>>v2[i];
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  cout<<"[";
  Fn(v1,v2);
  for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<", ";
  if(ans.size()>1) cout<<ans[ans.size()-1];
  cout<<"]";
}
