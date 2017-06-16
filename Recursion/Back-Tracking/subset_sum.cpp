#include <iostream>
#include <vector>

using namespace std;
//typedef vector <int> vi;

int k=10;

bool check(int sum){
        if(sum<=k) return true;
        return false;
}

void print(int subset[], int sub_size){
        for(int i=0; i<sub_size; i++) cout<<subset[i]<<" ";
        cout<<endl;
}

void subsetGen(int array[],int index, int size, int sum, int subset[], int t, int sub_size){
        if(index==size) {
                if(sum==k) print(subset,sub_size);
                return;
        }

        subsetGen(array,index+1,size,sum,subset,t,sub_size);
        if(check(sum+array[index]))  {
                subset[t]=array[index];
                subsetGen(array,index+1,size,sum+array[index],subset,t+1,sub_size+1);
        }
}


int main(){
        int a[100],n, subset[100];
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        subsetGen(a,0,n,0, subset,0,0);
        return 0;
}
