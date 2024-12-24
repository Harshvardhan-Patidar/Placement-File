// sort the o,1,2 only

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={0,1,0,2,0,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0,mid=0,high=n-1;
    int temp;
    while(mid<=high){
        if(arr[mid]==0){
            temp=arr[low];
            arr[low]=arr[mid];
            arr[mid]=temp;
            low++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
            mid++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}