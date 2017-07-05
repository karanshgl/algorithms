#include <map>
#include <iostream>
#include "binTree.h"
using namespace std;

typedef  map<int, vector<int> > miv;

void setMap(Node *root, int hd, miv& m){
	if (root == NULL){
		return;
	}

	m[hd].push_back(root->data);

	setMap(root->left, hd - 1, m);	//left tree horizontal distance is 1 less than the parent
	setMap(root->right, hd + 1, m);
}


int main(){

	map<int, vector<int> > m;
	int hd = 0;
  Node *root = levelInput();
	setMap(root, hd, m);
  cout<<endl;
	for(miv::iterator it = m.begin(); it != m.end(); ++it){
		pair<const int, vector<int> > & p = *it;
		for(int i = 0; i < p.second.size(); ++i){
			cout << p.second[i] << " ";
		}
		cout << endl;
	}

}
