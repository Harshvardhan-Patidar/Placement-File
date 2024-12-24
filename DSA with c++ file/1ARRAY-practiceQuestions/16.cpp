// An array of price is given, task is to find maximum profit which I get

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n){
    int minIndex=0,maxIndex=0,min=arr[0],max=0;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            minIndex++;
        }
    }
    maxIndex=minIndex;
    for(int j=0;j<n;j++){
        if(arr[j]>=max && j>minIndex){
            max=arr[j];
            maxIndex++;
        }
    }
    cout<<"If you buy shock on "<<minIndex+1<<" day and sell on "<<maxIndex+2<<" day you book profit of "<<max-min;
}
void secondApproch(int arr[],int n){
    int maxProfit=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[j]-arr[i]>maxProfit){
                maxProfit=arr[j]-arr[i];
            }
        }
    }
    cout<<"Max profit: "<<maxProfit;
}
void thirdApproch(int arr[],int n){
    int minPrice=INT_MAX,maxProfit=0;
    for(int i=0;i<n;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        maxProfit=max(maxProfit,arr[i]-minPrice);
    }
    cout<<"Max profit: "<<maxProfit;
}
int main(){
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    firstApproch(arr,n);
    cout<<endl;
    secondApproch(arr,n);
    cout<<endl;
    thirdApproch(arr,n);
    return 0;
}