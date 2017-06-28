//5th element from end

#include<iostream>
#include "mylist.h"

using namespace std;

Node *elementEnd(Node *head, int n){
  Node *slow = head;
  Node *fast=head;
  for(int i=0;i<n && fast;i++) fast=fast->next;
  while(slow&&fast){
    slow=slow->next;
    fast=fast->next;
  }
  return slow;
}

int main(){

Node *head=takeInput();
//head=rev(head);
//print(head);
int num;
cin>>num; //nth number from the end
Node *ans=elementEnd(head,num);
if(ans) cout<<ans->data<<endl;

}
