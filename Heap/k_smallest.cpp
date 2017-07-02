#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class more{
public:
  bool operator()(int x, int y){
    return x>y;
  }
};


// bool more(int x, int y){
//   return x > y;
// }

int main(){

  //priority_queue <int> q; //maxHeap
  priority_queue<int, vector<int>, more> q;
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  random_shuffle(arr,arr+10);
  int k,i;
  cin>>k;
  for(i=0;i<k;i++) q.push(arr[i]);
  for(;i<10;i++){
    int maxElement = q.top();
    if(maxElement < arr[i]){
      q.pop();
      q.push(arr[i]);
    }
  }

  while(!q.empty()){
    cout<<q.top()<<" ";
    q.pop();
  }

}
