#include<iostream>

using namespace std;


class Node{
public:
  int data;
  Node * next;
  Node(int n){
    data = n;
    next = NULL;
  }
};

Node *takeInput(int n, Node *head=NULL){
  Node *temp=new Node(n);
  if(head==NULL) return temp;
  else{
    temp->next=head;
    return temp;
  }
}

void print(Node *head){
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
}

int main(){

  Node *head = takeInput(5);
  head = takeInput(4,head);
  print(head);
  return 0;
}
