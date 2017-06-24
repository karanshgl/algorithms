#include<iostream>
#include "mylist.h"

using namespace std;

Node *kRev(Node *head, int k){
if(head==NULL) return head;

Node *nAhead=head;
for(int i=1; i <k && nAhead->next;i++ ) nAhead=nAhead->next;

Node *nextNode = nAhead->next;
nAhead->next=NULL;
Node *newHead = rev(head);
head->next = kRev(nextNode,k);
return newHead;
}

int main(){
  Node *head=takeInput();
  int k;
  cin>>k;
  head=kRev(head,k);
  print(head);
}
