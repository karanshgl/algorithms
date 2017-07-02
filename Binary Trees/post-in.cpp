#include<iostream>
#include "binTree.h"

int i;
int find(int in[], int be, int en, int data){
  while(be<=en){
    if(data==in[be]) return be;
    be++;
  }
  return -1;
}

Node *makeTree(int in[], int post[], int be, int en){
  if(be>en) return NULL;

  Node *root= new Node(post[i--]);

  int index = find(in,be,en,root->data);

  root->right = makeTree(in,post,index+1,en);
  root->left = makeTree(in, post, be, index -1);
  return root;
}

int main(){
  int in[100],post[100];
  int n;
  cin>>n;
  for(int j=0;j<n;j++) cin>>in[j];
  for(int j=0;j<n;j++) cin>>post[j];

  Node *root = makeTree(in,post,0,n-1);
  printLevel(root);
}
