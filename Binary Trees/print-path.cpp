#include<iostream>
#include<vector>
#include "binTree.h"

using namespace std;

void path(Node *root, vector<int> p){
//goes through the tree and prints the path
  if(root->left==NULL && root->right==NULL){
     for(int i=0;i<p.size();i++) cout<<p[i]<<"->";
    cout<<root->data<<endl;
    return;
  }
  p.push_back(root->data);
  if(root->left) path(root->left,p);
  if(root->right) path(root->right,p);
  p.pop_back();
}

int main(){
  Node *root=levelInput();
  vector<int> p;
  path(root,p);
  return 0;
}
