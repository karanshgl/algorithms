#include<iostream>
#include<climits>
#include "binTree.h"

bool isBST(Node *root, int minVal, int maxVal){
  if(root==NULL) return true;

  return(
    root->data >minVal && root->data <=maxVal &&
    isBST(root->left,minVal,root->data) &&
    isBST(root->right,root->data,maxVal)
  );
}

int main(){
  Node *root = levelInput();
  cout<<isBST(root,INT_MIN,INT_MAX);
}
