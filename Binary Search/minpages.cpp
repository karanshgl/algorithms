#include<iostream>

using namespace std;

int min(int &x, int &y){
  return ( x > y? y : x);
}

bool isPossible(int pages[], int atmostPages, int n, int students){
  int maxPage = 0 ;
  int studentRequired=1;

  for(int i = 0; i < n; i++){
    if(pages[i] > atmostPages) return false;
    else if(pages[i] + maxPage <= atmostPages) maxPage+=pages[i];
    else{
      studentRequired++;
      maxPage=pages[i];
      if(studentRequired>students) return false;
    }
  }
  return true;
}


int minPages(int pages[], int students, int n){
  int low = 0, high=0;
  for(int i=0;i<n;i++) high+=pages[i];
  int maxPages = high;
  int mid;
  while(low<=high){
    mid=(low+high)/2;
    if(isPossible(pages,mid,n,students)){
      maxPages=min(maxPages,mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return maxPages;
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr) / sizeof(int);
	int students;
	cin >> students;
	int ans = minPages(arr, students, n);
	cout << ans;
}
