#include<iostream>
#include<queue>

using namespace std;

class more{
public:
  bool operator ()(int a, int b){
    return a > b;
  }
};

typedef priority_queue < int, vector<int> , more > mp;

void balanceHeap(mp &minHeap, priority_queue <int> &maxHeap){
  if(minHeap.size() > maxHeap.size()){
    while(minHeap.size()>maxHeap.size()){
      int temp = minHeap.top();
      minHeap.pop();
      maxHeap.push(temp);
    }
  }
  else if(maxHeap.size() > minHeap.size()){
    while(maxHeap.size()>minHeap.size() + 1){
      int temp = maxHeap.top();
      maxHeap.pop();
      minHeap.push(temp);
    }
  }
}

void clear(mp &minHeap, priority_queue <int> &maxHeap){
  while(!minHeap.empty()) minHeap.pop();
  while(!maxHeap.empty()) maxHeap.pop();
}

void runMedian(){
  mp minHeap;
  priority_queue <int> maxHeap;

  int num;
  while(!cin.eof()){
    cin>>num;
    if(num==0){
      //To clean the heaps
      clear(minHeap,maxHeap);
      cout<<endl;
      continue;
    }

    if(num == -1){
      //Display the median
      if(!maxHeap.empty()){
        //Median is always in the maxHeap and is removed after it is displayed
        cout<<maxHeap.top()<<endl;
        maxHeap.pop();
        balanceHeap(minHeap, maxHeap);
        continue;
      }

      else return; //too many -1s
    }

    if(maxHeap.empty()){
      //maxHeap contains the median, it cannot be empty
      maxHeap.push(num);
      continue;
    }
    else if(minHeap.empty()){
      //Have to keep maxHeap and minHeap balanced
       minHeap.push(num);
       continue;
    }

    if(num > maxHeap.top()){
      //Maintaing a sequence if number is greater than maxHeap top then it goes to minHeap
      minHeap.push(num);
    }
    else{
      maxHeap.push(num);
    }
    balanceHeap(minHeap, maxHeap); //function to balance the Heap
  }
}


int main(){

runMedian();

}
