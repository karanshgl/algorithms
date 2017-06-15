#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vi;

int k=10;

bool check(int sum){
        if(sum<=k) return true;
        return false;
}

void print(vi subset){
        for(int i=0; i<subset.size(); i++) cout<<subset[i]<<" ";
        cout<<endl;
}

void subsetGen(int array[],int index, int size, int sum, vi subset, int t){
        if(index==size) return;

        if(sum==k) {
                print(subset);
                subsetGen(array, index,size,sum-array[index], subset, t-1);
                return;
        }
        subset.resize(t+1);
        for(int i=index; i<size; i++) {
                if(check(sum+array[i])) {
                        subset[t]=array[i];
                        subsetGen(array,i+1,size,sum+array[i], subset,t+1);
                }
        }
}


int main(){
        int a[100],n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        vi subset;
        subsetGen(a,0,n,0, subset,0);
        return 0;
}
