// Task is to find the upto k largest element from array using heap

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(pq.size()>k){
        pq.pop();
    }
    while(pq.size()>0){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}