#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;


class Node{
public:
  int data;
  Node *next;
  Node *random;
  Node(int i){
    data=i;
    next=NULL;
    random=NULL;
  }
};



void addToEnd(Node* &head, Node* nodeToAdd){
	if (head == NULL){
		head = nodeToAdd;
		return;
	}
  Node *temp=head;
  while(temp->next) temp=temp->next;
	temp->next = nodeToAdd;
}


Node* takenInput(int n){
	//take n numbers and add each successive number to the front of LL
	Node * head = NULL;
  int num;
	for(int i=0;i<n;i++){
    cin>>num;
		Node * newNode = new Node(num);
		addToEnd(head, newNode);
	}
	return head;
}


void print(Node *head){
  while(head){
    cout<<head->data<<" ("<<(head->random?head->random->data:-1)<<") ";
    head=head->next;
  }
  cout<<endl;
}


void setRandom(Node *head){
  vector<Node *> v;
  Node *tmp=head;
  while(tmp){
    v.push_back(tmp);
    tmp=tmp->next;
  }
  random_shuffle(v.begin(),v.end());

  for(int i=0;i<v.size()-1;i++){
    v[i]->random = v[i+1];
  }
}


Node *cloneLL(Node *head){
//Without using maps
  Node *cloneHead = NULL, *cloneTail=NULL;

  Node *it = head;

  while(it){
    //Created a combined list
    Node *tmp = new Node(it->data);
    tmp->next=it->next;
    it->next=tmp;
    it=it->next->next;
  }
  it=head;

  while(it && it->next){
    //loop to initialize random pointers in new list
    if(it->random){
      it->next->random = it->random->next;
    }
    it=it->next->next;
  }

  it=head;
  while(it && it->next){
    //loop to separate the new list
    Node *tmp = it->next;
    it->next=it->next->next;
    if(cloneHead==NULL){
      cloneHead=tmp;
      cloneTail=tmp;
    }
    else{
      cloneTail->next=tmp;
      cloneTail=tmp;
    }
    it=it->next;
  }
  return cloneHead;
}

Node *cloneMap(Node *head){
  map<Node*,Node*> m;

  //fill map
  Node *oHead=head;
  Node *cloneHead=NULL, *cloneTail=NULL;
  while(oHead){
    Node *newNode = new Node(oHead->data);
    if(cloneHead==NULL){
      cloneHead = newNode;
      cloneTail = newNode;
    }
    else{
      cloneTail->next = newNode;
      cloneTail = newNode;
    }

    m[oHead] = newNode;
    oHead = oHead->next;
  }

  oHead = head;
  while(oHead){
    m[oHead]->random = m[oHead->random];
    oHead = oHead->next;
  }

  return cloneHead;

}


int main(){
  Node *head = takenInput(10);
  setRandom(head);
  Node *cloneHead = cloneMap(head);
  print(head);
  print(cloneHead);
}
