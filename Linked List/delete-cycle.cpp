#include<iostream>
#include "mylist.h"

using namespace std;


Node *detectCycle(Node *head){

  Node *slow=head;
  Node *fast=head;
  while(slow && fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast) return slow;
  }
  return NULL;
}


void deleteCycle(Node *head, Node *kNode){
  if(head==NULL) return;

  Node *prev=NULL;
  while(head!=kNode){
    prev=kNode;
    head=head->next;
    kNode=kNode->next;
  }
  if(prev) prev->next=NULL;
}


int main(){
  Node * head = takeInput();
  	print(head);
  	head->next->next->next->next = head->next; //4th element is linked to 2nd

  	// bool isCycle = detectCycle(head);
  	deleteCycle(head, detectCycle(head));
  	print(head);

  return 0;
}
