#include<iostream>
#include "mylist.h"

using namespace std;


Node *merge(Node *left, Node *right){
  if(left==NULL) return right;
  if(right==NULL) return left;

  if(left->data<right->data){
    left->next=merge(left->next,right);
    return left;
  }
  else{
    right->next=merge(left,right->next);
    return right;
  }
}

void mergeSort(Node *&head){
  if(head==NULL) return;
  if(head->next==NULL) return;

  Node *middle = mid(head);
  Node *right =  middle->next;
  middle->next=NULL;
  mergeSort(head);
  mergeSort(right);
  Node * sorted = merge(head,right);
  head=sorted;

}

int main(){
  Node *head = takeInput();
  print(head);
  mergeSort(head);
  print(head);
  return 0;
}
