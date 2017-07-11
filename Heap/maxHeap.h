#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class maxHeap{
  vector<T> heap;
  int len;
  int parent(int i){ return i>>1; }
  int left(int i){ return i<<1; }
  int right(int i){ return (i<<1) + 1; }

  void heapify(int index){
    if(index>=len) return;

    int pos = index;
    if(left(pos)<=len && heap[left(pos)] > heap[pos]) pos = left(pos);
    if(right(pos)<=len && heap[right(pos)]> heap[pos]) pos = right(pos);

    if(pos==index) return;

    swap(heap[pos],heap[index]);
    heapify(pos);
  }

public:
  maxHeap(){
    heap.push_back(T());
    len=0;
  }

  bool isEmpty(){
    return len==0;
  }

  void push(T data){
    heap.push_back(data);
    len++;
    int i=len;

    while(parent(i)>=1 && heap[i] > heap[parent(i)]){
      swap(heap[i],heap[parent(i)]);
      i=parent(i);
    }
  }

  T top(){
    if(len>0) return heap[1];
    else return T();
  }

  void pop(){
    if(len<1) return;

    swap(heap[1],heap[len]);
    heap.pop_back();
    len--;
    heapify(1);
  }

  int size(){ return len; }
};
