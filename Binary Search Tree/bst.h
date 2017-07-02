#include<iostream>
#include<queue>

using namespace std;

class Node{

public:
  int data;
  Node *left;
  Node *right;
  Node(int n){
    data=n;
    left=NULL;
    right=NULL;
  }
};


void printLevel(Node *root){
  queue <Node *> q;
  q.push(root);
  q.push(NULL);
  cout<<root->data<<endl;
  while(!q.empty()){
    Node *cur=q.front();
    q.pop();
    if(cur==NULL){
      cout<<endl;
      if(!q.empty()) q.push(NULL);
      continue;
    }
    if(cur->left){
      cout<<cur->left->data<<" ";
      q.push(cur->left);
    }
    if(cur->right){
      cout<<cur->right->data<<" ";
      q.push(cur->right);
    }

  }
}

Node * insertBst(Node *root, int data){
  if(root==NULL){
    Node *tmp = new Node(data);
    return tmp;
  }

  if(root->data > data) root->left = insertBst(root->left,data);
  else root->right =insertBst(root->right,data);

  return root;
}

Node *takeInput(){

  int n;
  Node *root=NULL;
  while(cin>>n && n!=-1){
    root = insertBst(root,n);
  }
  return root;
}

void printPre(Node *root){
  if(root==NULL) return;

  cout<<root->data<<" ";
  printPre(root->left);
  printPre(root->right);

}


void printIn(Node *root){
  if(root==NULL) return;

  printIn(root->left);
  cout<<root->data<<" ";
  printIn(root->right);
}

void printPost(Node *root){
  if(root==NULL) return;

  printPost(root->left);
  cout<<root->data<<" ";
  printPost(root->right);
}



ostream& operator <<(ostream &output,Node* &root){
  printLevel(root);
  return output;
}


istream& operator >>(istream &input,Node* &root){
  root=takeInput();
  return input;
}

int sumTree(Node *&root){
  if(root==NULL) return 0;

  root->data+=sumTree(root->left);
  root->data+=sumTree(root->right);
  //cout<<root;
  return root->data;
}


bool find(Node *root, int data){
  if(root==NULL) return false;
  if(root->data==data) return true;

  if(find(root->left,data)||find(root->right,data)) return true;
  return false;
}
