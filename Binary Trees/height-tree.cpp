#include<iostream>
#include "binTree.h"

using namespace std;

int abs(int a){
  return (a>0?a:-a);
}

int height(Node *root){
  if(root==NULL) return 0;

return 1 + max(height(root->left),height(root->right));;
}

int diameter(Node *root){
  if(root==NULL) return 0;
int left = diameter(root->left);
int right = diameter(root->right);
int m = max(left,right);
return max(m,height(root->left) + height(root->right) +1);
}

class Pair{
public:
  int height,diameter;
  Pair(int a, int b){
    height = a;
    diameter = b;
  }
};

class Pair_balance{
public:
  bool isB;
  int height;
  Pair_balance(int a, bool b){
    height =a;
    isB = b;
  }
};

Pair diameter_opt(Node *root){
  if(root==NULL) return Pair(0,0);

  Pair left = diameter_opt(root->left);
  Pair right =  diameter_opt(root->right);
  Pair cur(0,0);
  cur.height = max(left.height, right.height) + 1 ;
  cur.diameter= max(max(left.diameter,right.diameter),(left.height+right.height+1));
  return cur;
}

bool isBalanced(Node *root){
  if(root==NULL) return true;
  if(abs(height(root->left)-height(root->right))<=1){
    if(isBalanced(root->left) && isBalanced(root->right)) return true;
  }
  return false;
}

Pair_balance isBal(Node *root){
  if(root==NULL) return Pair_balance(0,1);

  Pair_balance left = isBal(root->left);
  Pair_balance right =  isBal(root->right);
  int newHeight = max(left.height,right.height) + 1;
  if(abs(left.height-right.height)<=1 && left.isB && right.isB){
    return Pair_balance(newHeight,1);
  }
  return Pair_balance(newHeight,0);
}

int main(){
  Node *root = levelInput();
  printLevel(root);
  Pair_balance p = isBal(root);
  cout<<p.isB;
}
