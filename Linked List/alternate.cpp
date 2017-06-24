//Program to delete alternate nodes

#include<iostream>
#include "mylist.h"

using namespace std;

void alternate(Node *head){
  if(head==NULL) return;
  
  Node *cur=head;
  Node *ahead=head->next;
  while(cur && ahead){
    cur->next=ahead->next;
    delete(ahead);
    cur=cur->next;
    if(cur) ahead=cur->next;
  }
}

int main(){
  Node *head=takeInput();
  alternate(head);
  print(head);
}
