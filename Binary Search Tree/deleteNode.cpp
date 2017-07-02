#include<iostream>
#include "bst.h"

using namespace std;

void delNode(Node *root, int element){

if(root==NULL) return;

Node *parent=NULL;
Node *toDel =root;
bool child=true; //true means left child
while(toDel){
  parent=toDel;
  if(element < toDel->data){
    toDel = toDel->left;
    child=true;
  }
  else if(element > toDel->data){
    toDel = toDel->right;
    child=false;
  }
  else break;
}

if(toDel==NULL) return;

if(parent){
  if(toDel->left){
    Node *left=toDel->left;
    Node *prev=NULL;
    while(left->right){
      prev=left;
      left=left->right;
    }
    swap(toDel->data,left->data);
    if(prev){
      prev->right=NULL;
      delete(left);
    }
    else{
      if(child) parent=parent->left;
      else parent=parent->right;
      delete(toDel);
    }
  }
}
}

int main(){
  Node *root=takeInput();
  int n;
  cin>>n;
  printLevel(root);
  delNode(root,n);
  printLevel(root);

}
