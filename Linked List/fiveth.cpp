//5th element from end

#include<iostream>
#include "mylist.h"

using namespace std;

Node *elementEnd(Node *head, int n){
  Node *fast = head;
  Node *prev;
  int flag=1;
  while(fast&&flag){
    prev=fast;
     for(int i=1;i<n;i++){
       if(fast->next==NULL){
         flag=0;
         break;
       }
       fast=fast->next;
    }
    if(flag==0) return NULL;
   }
  return prev;
}

int main(){

Node *head=takeInput();
head=rev(head);
print(head);
int num;
cin>>num; //nth number from the end
Node *ans=elementEnd(head,num);
if(ans) cout<<ans->data<<endl;

}
