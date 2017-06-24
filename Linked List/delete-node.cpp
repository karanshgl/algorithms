#include<iostream>
#include "mylist.h"

void delNode(Node *toDelete){
  if(toDelete==NULL) return;

  Node *prev;
  while(toDelete->next){
    prev=toDelete;
    toDelete->data = toDelete->next->data;
    toDelete=toDelete->next;
  }
  prev->next=NULL;
  delete(toDelete);
}

int main(){
  Node *head=takeInput();
  delNode(head->next);
  print(head);
}
