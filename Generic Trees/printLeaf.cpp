#include<iostream>
#include "genTree.h"
using namespace std;

void printLeaf(Node *root){
  if(root==NULL) return;

    bool flag=true;
  for(int i=0;i<root->child;i++){
      if(root->p[i]) flag=false;
  }
  if(flag){
      cout<<root->data<<" ";
      return;
  }
  for(int i=0;i<root->child;i++){
    printLeaf(root->p[i]);
  }
}

int main(){
  Node *root=inputTree();
  printLeaf(root);
}
