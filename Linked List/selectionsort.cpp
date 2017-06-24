#include<iostream>
#include "mylist.h"

using namespace std;

Node *selSort(Node *head){
  if(head->next==NULL) return head;

  Node *cur=head, *ahead;
  Node *minNode=head;
  bool nodeHead = true;
  int min_data=head->data;
  while(cur && cur->next){
    ahead=cur->next;
    if(ahead->data<min_data){
      minNode=cur;
      min_data=ahead->data;
      nodeHead = false;
    }
    cur=cur->next;
  }
  if(nodeHead){
    head->next=selSort(head->next);
  }
  else{
    Node *newHead = minNode->next;
    minNode->next=newHead->next;
    newHead->next=selSort(head);
    head=newHead;
  }
return head;
}

int main(){
  Node *head=takeInput();
  head = selSort(head);
  print(head);
}
