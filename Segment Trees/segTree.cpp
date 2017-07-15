#include<iostream>
using namespace std;

const int N = 1000;

int arr[]={1,2,3,4,5};
int tree[2*N];

int left(int i) { return i<<1; }
int right(int i) { return (i<<1) + 1; }


void build(int root, int be, int en){
  if(be>en) return;

  if(be==en){
    tree[root]=arr[be];
    return;
  }

  int mid = (en+be)/2;
  build(left(root),be,mid);
  build(right(root),mid+1,en);

  tree[root] = min(tree[left(root)],tree[right(root)]);
}

int search(int root, int be, int en, int i, int j){

  if(j < be || i>en) return 10000;

  if(be>=i && en<=j) return tree[root];

  int mid = (be+en)/2;
  if(i<=mid && j<=mid) return search(left(root),be,mid,i,j);
  else if(i>mid && j>mid) return search(right(root),mid+1,en,i,j);

  int leftAns = search(right(root),mid+1,en,i,j);
  int rightAns = search(left(root),be,mid,i,j);

  return min(leftAns, rightAns);
}

void update(int root,int be, int en, int index, int value){


  if(be==index && en==index){
    tree[root]=value;
    return;
  }

  if(be>=en) return;

  int mid=(be+en)/2;

  update(left(root),be,mid,index,value);
  update(right(root),mid+1,en,index,value);

  tree[root] = min(tree[left(root)],tree[right(root)]);
}

int main(){
  build(1,0,4);

  for(int i=0;i<10;i++) cout<<tree[i]<<" ";
  cout<<endl;
  cout<<search(1,0,4,1,2);
  update(1,0,4,0,100);
  cout<<endl;
  for(int i=0;i<10;i++) cout<<tree[i]<<" ";

}
