#include<iostream>
#include "binTree.h"
using namespace std;

class Sum{
public:
  int in;
  int ex;
  Sum(int a,int b){
    in=a;
    ex=b;
  }
};

Sum calSum(Node *root){

  if(root==NULL) return Sum(0,0);

  Sum left = calSum(root->left);
  Sum right = calSum(root->right);

  Sum cur(0,0);
  cur.in = left.ex + right.ex + root->data;
  cur.ex = max(left.ex,left.in) + max(right.ex,right.in);
  return cur;
}

int main(){
  Node *root = levelInput();
  Sum a = calSum(root);
  cout<<max(a.in,a.ex)<<endl;
}
