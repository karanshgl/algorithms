#include<iostream>
#include "minHeap.h"
#include<string>
using namespace std;

class Book{

public:
  int isdn;
  string author;
  Book(){}
  Book(int i, string x){
    isdn = i;
    author = x;
  }

  bool operator<(const Book &B){
    return author.size() < B.author.size();
  }
};

void printHeap(Heap<Book> h){
  int i=1,j=1,s=0;
  while(!h.isEmpty()){
    cout<<h.top().author<<" ";
    h.pop();
    s++;
    if(s%j==0){
      cout<<endl;
      j=j<<1;
    }
  }
}


int main(){
  Heap<Book> h;

  //for(int i=5;i>=1;i--) h.push(i);
  Book B1(1,"Karan");
  Book B2(2,"Kar");
  h.push(B1);
  h.push(B2);
  printHeap(h);
  h.pop();
  h.pop();
  cout<<endl<<endl;
  printHeap(h);
}
