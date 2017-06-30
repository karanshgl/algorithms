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

Node *levelInput(){
  int data;
  cin>>data;
  if(data==-1) return NULL;

  Node *root=new Node(data);
  queue <Node *> q;
  q.push(root);
  while(!q.empty()){
    Node *cur=q.front();
    q.pop();
    int leftData; cin>>leftData;
    if(leftData!=-1){
      Node *tmp = new Node(leftData);
      cur->left = tmp;
      q.push(tmp);
    }
    int rightData; cin>>rightData;
    if(rightData!=-1){
      Node *tmp=new Node(rightData);
      cur->right=tmp;
      q.push(tmp);
    }
  }
  return root;
}

void printLevel(Node *root){
  queue <Node *> q;
  q.push(root);
  //int i=2,j=2;
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
    //i++;
    if(cur->right){
      cout<<cur->right->data<<" ";
      q.push(cur->right);
    }
    //i++;
    // if(i%j==0){
    //   cout<<endl;
    //   j<<=1;
    // }

  }
}

Node *takeInput(){

  int data;
  cin>>data;

  if(data==-1) return NULL;

  Node *root = new Node(data);
  root->left=takeInput();
  root->right=takeInput();
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
  root=levelInput();
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
