#include <iostream>

using namespace std;

void merge(int arr[100], int low, int high){
        int i=low, j,k=low, mid=(low+high)/2;
        j=mid+1;
        int temp[100];
        while(i<=mid&&j<=high) {
                if(arr[i]<arr[j]) {
                        temp[k++]=arr[i];
                        i++;

                }
                else{
                        temp[k++]=arr[j];
                        j++;

                }
        }

        while(j<=high)
                temp[k++]=arr[j++];

        while(i<=mid)
                temp[k++]=arr[i++];

        for(i=low; i<k; i++) {
                arr[i]=temp[i];
        }

}

void partition(int arr[1000], int low, int high){
        if(low>=high)
                return;

        int mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        merge(arr,low,high);
}

int main(){
        int n,i, arr[100];
        cin>>n;
        for(i=0; i<n; i++)
                cin>>arr[i];
        partition(arr,0,n-1);
        for(i=0; i<n; i++)
                cout<<arr[i]<<" ";
        return 0;
}
