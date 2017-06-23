#include<iostream>
#include "mylist.h"

using namespace std;



void bubblesort(Node* &head){
  int len = length(head);
  for(int i=0;i<len;i++){
    Node *prev = NULL;
    Node *cur = head;
    while(cur!=NULL&&cur->next!=NULL){
      Node *ahead = cur->next;
      if(cur->data>ahead->data){
        if(prev==NULL){
          cur->next=ahead->next;
          ahead->next=cur;
          head = ahead;
          prev = ahead;
        }
        else{
          prev->next=ahead;
          cur->next=ahead->next;
          ahead->next=cur;
          prev=ahead;
        }
      }
      else{
        prev=cur;
        cur=cur->next;
      }
    }
  }
}

int main(){
  Node *head=takeInput();
  print(head);
  cout<<endl;
  bubblesort(head);
  print(head);
  return 0;
}
