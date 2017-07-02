#include<iostream>
#include "bst.h"

using namespace std;

Node *makeBalancedTree(int arr[], int be, int en){
  if(be>en) return NULL;

  int mid=(be+en)/2;
  Node *root=new Node(arr[mid]);
  root->left = makeBalancedTree(arr,be,mid-1);
  root->right =  makeBalancedTree(arr,mid+1,en);
  return root;
}

int main(){
  int arr[100];
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  Node *root=makeBalancedTree(arr,0,n-1);
  printLevel(root);
}
