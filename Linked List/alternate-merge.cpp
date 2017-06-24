#include<iostream>
#include "mylist.h"

using namespace std;

Node *merge(Node *left, Node*right){
  if(left==NULL) return right;
  if(right==NULL) return left;

  left->next=merge(right,left->next);
  return left;
}

int main(){
  Node *l1=takeInput();
  Node *l2=takeInput();
  Node *head=merge(l1,l2);
  print(head);
}
