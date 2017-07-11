#include<iostream>
#include "bst.h"

using namespace std;

Node *successor(Node *root){
  if(root==NULL) return NULL;

  Node *tmp = root->right;
  while(tmp && tmp->left){
    tmp=tmp->left;
  }
  return tmp;
}


Node *deletNode(Node *root, int d){
  if(root==NULL) return NULL;

  if(root->data==d){

    if(!root->left && !root->right){
      delete root;
      return NULL;
    }
    else if(!root->left){
      Node* tmp = root->right;
      delete root;
      return tmp;
    }
    else if(!root->right){
      Node *tmp = root->left;
      delete root;
      return tmp;
    }
    else{
      Node *justGreater = successor(root);
      swap(justGreater->data,root->data);
      root->right = deletNode(root->right,justGreater->data);
      return root;
    }
  }
  if(d < root->data) root->left = deletNode(root->left,d);
  else root->right  = deletNode(root->right,d);
  return root;
}

int main(){
  Node *root=takeInput();
  root=deletNode(root,1);
  printLevel(root);
}
