#include<iostream>
#include "hashtable.h"

int main(){
  Hashtable h;
  h.insert("Hello",123);
  h.insert("World", 456);
  cout<<h.getData("Hello")<<" "<<h.getData("World");
}
