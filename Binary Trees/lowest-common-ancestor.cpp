#include<iostream>
#include "binTree.h"

using namespace std;


Node *comAncestor(Node *root, int a, int b){
  //A function that returns the node of the lowest common ancestor, where b>a
  if(root==NULL) return NULL;

  if(find(root->left,a) && find(root->right,b)) return root;
  //If a is in the left subtree and b is in the right subtree, then root is the ancestor
  if(find(root->left,b) && find(root->right,a)) return root;
  //If a is in the right subtree and b is in the left subtree

  Node *tmpLeft = comAncestor(root->left,a,b);
  //If it exists in the left subtree
  Node *tmpRight = comAncestor(root->right,a,b);
  //If it exists in the right subtree
  if(tmpLeft) return tmpLeft;
  if(tmpRight) return tmpRight;
  return NULL;
}



int main(){
  Node *root = levelInput();
  int a,b;
  cin>>a>>b;
  Node *com = comAncestor(root,a,b);
  if(com) cout<<com->data;
}
