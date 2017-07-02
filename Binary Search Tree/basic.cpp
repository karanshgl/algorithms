#include<iostream>
#include "bst.h"
using namespace std;


void printRange(Node *root, int k1, int k2){
  if(root==NULL) return;

  if(root->data > k1) printRange(root->left,k1,k2);
  if(root->data >= k1 && root->data <= k2) cout<<root->data<<" ";
  if(root->data < k2) printRange(root->right,k1,k2);
  
}

Node *search(Node *root, int data){
  if(root==NULL) return NULL;

  if(root->data == data) return root;
  if(root->data < data) return search(root->right,data);
  else return search(root->left,data);

}


int main(){
  Node *root=takeInput();
  //printLevel(root);
  // Node *element = search(root,5);
  // if(element) cout<<element->data;
  // else cout<<"-1";
  printRange(root,9,12);
}
