#include<iostream>
#include<stdlib.h>
#include "mylist.h"

using namespace std;

Node* add(Node *num1, Node *num2){
  Node *head=NULL;
  int carry=0,sum=0;
  while(num1||num2){
    sum=carry;
    if(num1) sum+=num1->data;
    if(num2) sum+=num2->data;

      carry=sum/10;
      sum=sum%10;

    Node *temp = new Node(sum);
    addToFront(head, temp);

    if(num1) num1=num1->next;
    if(num2) num2=num2->next;
}

  if(carry){
    Node *temp = new Node(carry);
    addToFront(head, temp);
  }

  return head;

}

int main(){
  Node *h1=takeInput(0); //Adding to front
  Node *h2=takeInput(0);
  Node *ans= add(h1,h2);
  print(ans);
}
