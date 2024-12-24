// our task is to make a wave like array structure means first element is greaker then less then vice versa

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        else if(arr[i]>=arr[i+1] && (i+1)%2==0){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        else{
            continue;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void secondApproch(int arr[],int n){
    int temp;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i%2==0){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={20,10,8,6,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    firstApproch(arr,n);
    cout<<endl;
    secondApproch(arr,n);
    return 0;
}