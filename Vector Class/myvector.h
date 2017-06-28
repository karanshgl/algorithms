#include<iostream>
using namespace std;

template <typename T>
class Vector {
T *data;
int len;
int capacity;

void reconstruct(){
        T *newData = new T [2*capacity];
        for(int i=0; i<len; i++) newData[i]=data[i];
        delete [] data;
        data=newData;
        capacity=2*capacity;
}

public:

Vector(){
        data=new T[10];
        capacity=10;
        len=0;
}

Vector(int i){
        data=new T [i];
        capacity=i;
        len=0;
}

~Vector(){
        delete [] data;
}


int size(){
        return len;
}

void push_back(T newElement){
        //data=(int *)realloc(data,(len+1)*sizeof(int));
        if(len>=capacity) reconstruct();
        data[len]=newElement;
        ++len;
        //delete(newData);
}

T pop_back(){
        if(len<0) return 0;
        T temp=data[len-1];
        //data=(int *)realloc(data,(len-1));
        data[len-1]=0;
        --len;
        return temp;
}

int operator [](int i){
        if(i>=len||i<0) return -1;
        return data[i];
}

friend ostream& operator <<(ostream &output,Vector &V){
  for(int i=0;i<V.size();i++) output<<V[i]<<" ";
  output<<endl;
  return output;
}
// friend istream& operator <<(istream &input,Vector &V){
//
//   return input;
// }

};
