#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wavesort(vector<int> &v){
        sort(v.begin(),v.end());
        int tmp;
        int c = v.size()%2;
        for(int i=0; i<v.size() - c; i+=2) {
                tmp=v[i]; v[i] = v[i+1]; v[i+1] = tmp;
        }
}

int main(){

        vector <int> v;
        int n;
        cin>>n;
        v.resize(n);
        for(int i=0; i<n; i++) cin>>v[i];
        wavesort(v);
        for(int i=0; i<n; i++) cout<<v[i]<<" ";
        return 0;

}
