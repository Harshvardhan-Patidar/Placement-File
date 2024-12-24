// Find Maximum difference present between two elements such that larger element comes after smaller element int array

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void firstApproch(int arr[],int n){
    int maxDiff=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                if(arr[j]-arr[i]>maxDiff){
                    maxDiff=arr[j]-arr[i];
                }
            }
        }
    }
    cout<<"Max difference: "<<maxDiff;
}
void secondApproch(int arr[], int n){
    sort(arr,arr+n);
    cout<<"Max difference: "<<arr[n-1]-arr[0];
}
void thirdApproch(int arr[],int n){
    int maxDiff=arr[1]-arr[0];
    int minElement=arr[0];
    for(int i=1;i<n;i++){
        if(a[i]-minElement>maxDiff){
            maxDiff=a[i]-minElement;
        }
        if(a[i]<minElement){
            minElement=a[i]
        }
    }
    cout<<"Max didderence: "<<maxDiff;
}
int main(){
    int arr[]={7,1,3,8,4,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    firstApproch(arr,n);
    cout<<endl;
    secondApproch(arr,n);
    cout<<endl;
    thirdApproch(arr,n);
    return 0;
}