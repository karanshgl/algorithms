#include<iostream>
#include "binTree.h"

using namespace std;

bool findPath(Node *root, vector<Node*> &path, int k)
{
    if (root == NULL) return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);

    // See if the k is same as root's key
    if (root->data == k) return true;

    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}

Node* comAncestor(Node *root, int a, int b)
{
    // to store paths to n1 and n2 from the root
    vector<Node*> path1, path2;

    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return NULL
    if ( !findPath(root, path1, a) || !findPath(root, path2, b))
          return NULL;

    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}


int main(){
  Node *root = levelInput();
  int a,b;
  cin>>a>>b;
  Node *com = comAncestor(root,a,b);
  if(com) cout<<com->data;
}
