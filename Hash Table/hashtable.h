#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<string>
using namespace std;

class Node{

public:
  string key;
  int data;
  Node *next;

  Node(){}
  Node(string s, int d){
      key = s;
      data = d;
      next = NULL;
    }
  ~Node(){
    //if next is not null I am going to delete the whole list
    if (next !=NULL) delete(next);
  }
};

class Hashtable{
  Node **table;
  int size;
  int n;

  void clear(){
    for(int i=0;i<size;i++) table[i]=NULL;
  }

  int hash_function(string s){

    int pow = 1;
    int idx = 0;

    for(int i=0; i<s.size(); ++i){
      idx = idx + s[i]*pow;
      pow=pow*37;
      pow%=size;
      idx%=size;
    }
    return idx;
  }


  void rehash(){
    n=0;
    int oldSize = size;
    size = size*2;
    Node **oldTable = table;
    table = new Node*[size];
    for(int i=0;i<oldSize;i++){
      Node *ll= oldTable[i];
      while(ll){
      //  Node *toInsert = ll;
        insert(ll->key, ll->data);
        ll=ll->next;
      }
      delete oldTable[i];
    }
    delete [] oldTable;
    //table=newTable;
  }

public:

  Hashtable(){
    size = 7;
    table = new Node*[size];
    n=0;
    clear();
  }

  void insert(string s, int d){
    Node *newElement = new Node(s,d);
    int idx = hash_function(s);

    //inserting new element
    newElement->next = table[idx];
    table[idx] = newElement;
    ++n;

    double load_factor = 1.0*n/size;

    if(load_factor > 0.7) rehash();
  }

  int getData(string s){
    int idx = hash_function(s);
    Node *cur=table[idx];
    while(cur!=NULL){
      if(cur->key==s) return cur->data;
      cur=cur->next;
    }
    return -1;
  }

  bool empty(){
    return n==0;
  }

  int getSize(){
    return n;
  }

  void remove(string s){
    int idx = hash_function(s);
    Node *cur=table[idx];
    Node *prev = NULL;
    while(cur){
      if(cur->key==s){
        if(prev) prev->next = cur->next;
        else table[idx] = cur->next;
        --n;
        delete(cur);
        return;
      }
      prev=cur;
      cur=cur->next;
    }
  }

};

#endif
