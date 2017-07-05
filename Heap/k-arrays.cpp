#include<iostream>
#include<queue>

using namespace std;

class Triple{
public:
  int rowNumber;
  int index;
  int data;
  Triple(int d, int i, int j){
    data = d;
    rowNumber = i;
    index = j;
  }
};

class more{
public:
  bool operator()(Triple x, Triple y){
    return x.data>y.data;
  }
};

typedef priority_queue<Triple, vector<Triple>, more> pq;

vector<int> makeArray(int arr[][100], int k, int n){
pq q;
vector <int> ans;
for(int i=0;i<k;i++){
  Triple data(arr[i][0],i,0);
  q.push(data);
}

while(!q.empty()){
  Triple temp = q.top();
  q.pop();
  ans.push_back(temp.data);
  int newIndex = temp.index + 1;
  if(newIndex < n){
    Triple addNew(arr[temp.rowNumber][newIndex],temp.rowNumber,newIndex);
    q.push(addNew);
  }
}
return ans;
}



int main(){
  int arr[100][100];
  int k,n;
  cin>>k>>n;
  for(int i=0;i<k;i++){
    for(int j=0;j<n;j++) cin>>arr[i][j];
  }
vector<int> ans = makeArray(arr,k,n);
for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
cout<<endl;
}
