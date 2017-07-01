#include<iostream>
using namespace std;

class Node{
public:
  int data;
  int child;
  Node *p[100];
  Node(int d, int c){
    data=d;
    child=c;
    for(int i=0;i<c;i++) p[i]=NULL;
  }
};

Node* inputTree(){
  int data, children;
  cin>>data;
  cin>>children;
  Node *root=new Node(data,children);
  for(int i=0;i<children;i++){
    root->p[i] = inputTree();
  }
  return root;
}

void print(Node *root){
  if(root==NULL) return;

  cout<<root->data<<" ";
  for(int i=0;i<root->child;i++){
    print(root->p[i]);
  }
}


bool structTree(Node *a, Node *b){
  if(a==NULL&&b==NULL) return true;

  if(a==NULL||b==NULL) return false;
  if(a->child!=b->child) return false;
  if(a->data!=b->data) return false;

  for(int i=0;i<a->child;i++){
    if(!structTree(a->p[i],b->p[i])) return false;
  }
  return true;
}
