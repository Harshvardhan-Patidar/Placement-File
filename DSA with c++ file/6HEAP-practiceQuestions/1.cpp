// Our task is to find the maximun element using th Min Heap
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
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    int max=0;
    for(int i=n/2+1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<"Maximum element: "<<max;
    return 0;
}