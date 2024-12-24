#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]<arr[smallest]){
        smallest=l;
    }
    if(r<n && arr[r]<arr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}
void buildHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=0;i<n;i++){
        swap(arr[n-i-1],arr[0]);
        heapify(arr,n-i-1,0);
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Heap sort using Min heap: ";
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}