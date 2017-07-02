#include<iostream>
#include "bst.h"

Node *comAncestor(Node *root, int a, int b){
  //A function that returns the node of the lowest common ancestor, where b>a
  if(root==NULL) return NULL;
  //They don't have any ancestor i.e. at least one of them doesn't exist in the tree

  if(root->data >=a && root->data <=b) return root;
  else{
    if(root->data < a) return comAncestor(root->right,a,b);
    //If the root data is less than the lower element, both elements are to the right
    if(root->data > b) return comAncestor(root->left,a,b);
    //If the root data is greater than the larger element, both eleents are to the left
  }
  return NULL;
}

int main(){
  Node *root=takeInput();
  printLevel(root);
  int a,b;
  cin>>a>>b;
  Node *com = comAncestor(root,a,b);
  if(com) cout<<com->data<<" ";
}
