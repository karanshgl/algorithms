#include<iostream>
#include "binTree.h"

using namespace std;


Node* mirror(Node *root){
  if(root==NULL) return root;

  Node *temp;
  temp=root->left;
  root->left = mirror(root->right);
  root->right = mirror(temp);
  return root;
}

int main(){
  Node *root=levelInput();
  root=mirror(root);
}
