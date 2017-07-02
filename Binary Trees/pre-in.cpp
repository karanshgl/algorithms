#include<iostream>
#include "binTree.h"
#include<vector>
using namespace std;

int i;
int search(int in[], int be, int en, int element){

  while(be<en){
    if(in[be]==element) return be;
    be++;
  }
}
Node* makeTree(int in[],int pre[], int be, int en){
  if(be>en) return NULL;

  Node *root=new Node(pre[i++]);

  int idx = search(in,be,en,root->data);

  root->left = makeTree(in,pre,be,idx-1);
  root->right = makeTree(in,pre,idx+1,en);
  return root;
}

int main(){
  int a[100],b[100];
  int n;
  cin>>n;

  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  Node *root = makeTree(a,b,0,n-1);
  printLevel(root);
}
