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

Node* takeInput(){
	//take n numbers and add each successive number to the front of LL
	Node * head = NULL;
  int num;
	while(cin>>num&&num!=-1){
		Node * newNode = new Node(num);
		addToFront(head, newNode);
	}
	return head;
}


void print(Node *head){
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
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
  while(fast && fast->next){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
