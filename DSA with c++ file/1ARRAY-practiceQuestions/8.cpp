// Task is to find the majority element present in array but majority is greater then n/2

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n,int minOccure){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>minOccure){
            cout<<"Major element: "<<arr[i]<<endl;
            break;
        }
        else{
            count=0;
        }
    }
    if(count<minOccure){
        cout<<"No majority element occure";
    }
}

void secondApproch(int arr[],int n,int minOccure){
    int count=1;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            count++;
            if(count>minOccure){
                cout<<"Major element: "<<arr[i]<<endl;
                break;
            }
        }
        else{
            count=1;
        }
    }
}
int main(){
    int arr[]={4,2,4,4,8,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int minOccure=n/2;
    firstApproch(arr,n,minOccure);
    sort(arr,arr+n);
    cout<<endl;
    secondApproch(arr,n,minOccure);
    
    return 0;
}