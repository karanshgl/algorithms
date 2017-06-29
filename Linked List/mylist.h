#include<iostream>

using namespace std;

class Node{
public:
  int data;
  Node * next;
  Node(int n){
    data = n;
    next = NULL;
  }
};


int length(Node *head){
  int cnt=0;
  while(head){
    cnt++;
    head=head->next;
  }
  return cnt;
}

void addToFront(Node* &head, Node* nodeToAdd){
	if (head == NULL){
		head = nodeToAdd;
		return;
	}

	nodeToAdd->next = head;
	head = nodeToAdd;
}


void addToEnd(Node* &head, Node* nodeToAdd){
	if (head == NULL){
		head = nodeToAdd;
		return;
	}
  Node *temp=head;
  while(temp->next) temp=temp->next;
	temp->next = nodeToAdd;
}


Node* takeInput(int loc=1){
	//take n numbers and add each successive number to the front of LL
	Node * head = NULL;
  int num;
	while(cin>>num&&num!=-1){
		Node * newNode = new Node(num);
    if(loc==0) addToFront(head,newNode);
		else if(loc==1) addToEnd(head, newNode);
	}
	return head;
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
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

Node *reverse(Node *head){
  Node *prev=NULL;
  Node *cur = head;
  Node *ahead = head->next;
  while(cur&&ahead){
    ahead=cur->next;
    cur->next=prev;
    prev=cur;
    cur=ahead;
  }
  return prev;
}

Node *rev(Node *head){
  if(head->next==NULL) return head;

  Node *newHead = rev(head->next);
  head->next->next=head;
  head->next=NULL;
  return newHead;
}

Node *mid(Node *head){
  Node *slow=head;
  Node *fast=head;
  while(fast && fast->next && fast->next->next){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
