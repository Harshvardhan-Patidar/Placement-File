// our task is to move backward all zero from an given array and point is that the order of number is not change

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n,int temp[]){
    int j=0;
    for(int i=0;i<n;i++){
        temp[i]=0;
        if(arr[i]!=0){
            temp[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
        cout<<arr[i]<<" ";
    }
}

void secondApproch(arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[count]=arr[i];
            count++;
        }
    }
    while(count<n){
        arr[count]=0;
        count++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,0,2,0,3,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    firstApproch(arr,n,temp);
    cout<<endl;
    secondApproch(arr,n);
    return 0;
}