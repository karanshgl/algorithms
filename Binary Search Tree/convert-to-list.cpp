//A program to convert a binary search tree to a sorted linked list

#include<iostream>
#include<utility>
#include "bst.h"

using namespace std;

class LL{
  //Pair class
public:
  Node *head;
  Node *tail;
  LL(){
    head=NULL;
    tail==NULL;
  }
};

LL bstTolist(Node *root){
  if(root==NULL){
    //If node is NULL return a list with NULL head and tail
    LL l;
    l.head==NULL;
    l.tail=NULL;
    return l;
  }

  LL curList;

  LL left =  bstTolist(root->left);

  if(left.head!=NULL){
    //If there are elements to the left of the tree
    curList.head = left.head;
    //The current list would have its head equal to the left list
    left.tail->right=root;
    //The left list's tail points to the root of the sub tree
  }
  else{
    //left tree is empty, the current list would have the root as its head
    curList.head=root;
  }

  LL right = bstTolist(root->right);

  if(right.head!=NULL){
    //If there are elements to the right
    root->right=right.head;
    //The root points towards the list to the right
    curList.tail=right.tail;
    //The tail of the list is the tail of the right list
  }
  else{
    //If right list is empty, the tail of the current list would be the root
    curList.tail=root;
  }
  return curList;
}

void printList(LL list){
  Node *str = list.head;
  while(str!=NULL){
    cout<<str->data<<" ";
    str=str->right;
  }
}

int main(){
  Node *root = takeInput();
  LL list = bstTolist(root);
  printList(list);
}
