#include<iostream>
#include "mylist.h"




void del(Node *&head, int index){
  if(head==NULL) return;
  if(index==0){
    Node *toDelete=head;
    head=head->next;
    delete(toDelete);
    return;
  }
  Node *toDelete=head;
  Node *prev=head;
  for(int i=0;i<index;i++){
    prev=toDelete;
    toDelete=toDelete->next;
  }
  prev->next=toDelete->next;
  delete(toDelete);
}

int main(){
  int n,c,num;
  cin>>n>>c;
  Node *head=NULL;
  for(int i=0;i<n;i++){
    cin>>num;
    Node * newNode = new Node(num);
    addToEnd(head, newNode);
  }
  for(int i=0;i<c;i++){
    cin>>num;
    del(head,num);
    print(head);
  }


}
