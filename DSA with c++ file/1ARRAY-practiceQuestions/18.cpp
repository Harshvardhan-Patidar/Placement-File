// Array is given, our task is to find the duplicate number present in the array

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<" ";
                break;
            }
        }
    }
}
void secondApproch(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    int arr[]={1,2,2,3,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Duplicate number: ";
    // firstApproch(arr,n);
    // secondApproch(arr,n);
    return 0;
}