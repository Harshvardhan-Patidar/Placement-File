// Value is given, task is to find the subarray which sum is equal to value

#include <bits/stdc++.h>
using namespace std;
void firstApproch(int arr[],int n,int value){
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=sum+arr[i];
            if(sum==value){
                count++;
            }
        }
        sum=0;
    }
    cout<<"Total subarray with sum equal to "<<value<<": "<<count;
}
void secondApproch(int arr[],int n,int value){
    int sum=0,xSum=0,count=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==value){
            count++;
        }
        xSum=sum-value;
        if(mp.find(xSum) != mp.end()){
            count=count+mp[xSum];
        }
        mp[sum]++;
    }
    cout<<"Total subarray with sum equal to "<<value<<": "<<count;
}
int main(){
    int arr[]={5,3,2,-7,3,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int value=5;
    firstApproch(arr,n,value);
    secondApproch(arr,n,value);
    return 0;
}