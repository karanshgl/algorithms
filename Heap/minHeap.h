#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Heap{
  vector <T> v;
  int size;
  int parent(int i) { return i >> 1;}
  int left(int i) { return i << 1; }
  int right(int i){ return (i << 1) + 1; }

  void heapify(int i){
    if(i >=size) return;

    int pos=i;
    if(left(i) <= size && v[left(i)] < v[pos]) pos=left(i);
    if(right(i) <= size && v[right(i)] < v[pos]) pos=right(i);

    if(pos==i) return;
    swap(v[i],v[pos]);
    heapify(pos);
  }

public:
  Heap(){
    v.push_back(T());
    size=0;
  }

  void push(T data){
    v.push_back(data);
    ++size;

    int i=size;
    while(parent(i)>=1 && v[i] < v[parent(i)]){
      swap(v[parent(i)], v[i]);
      i=parent(i);
    }
  }

  void pop(){
    if(size < 1) return;

    swap(v[1],v[size]);
    v.pop_back();
    --size;
    heapify(1);
  }

  T top(){
    if(size < 1) return T();
    return v[1];
  }

  int len(){ return size; }

  bool isEmpty(){
    return ( size < 1? 1:0 );
  }
};
