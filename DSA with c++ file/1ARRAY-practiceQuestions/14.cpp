// given an binary arra, task is to find the maximun length of a contiguous subarray with equal number of 0 and

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void firstApproch(int arr[],int n){
    int one=0,zero=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            one++;
        }
        else if(arr[i]==0){
            zero++;
        }
    }
    if(one>=zero){
        cout<<"Max length: "<<2*zero;
    }else{
        cout<<"Max length: "<<2*one;
    }
}
void secondApproch(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            arr[i]=-1;
        }
    }
    unordered_map<int,int> mp;
    int cum_sum=0,max_len=0;
    for(int i=0;i<n;i++){
        cum_sum+=arr[i];
        if(cum_sum==0){
            max_len++;
        }
        if(mp.find(cum_sum)!=mp.end()){              // finding the cum_sum in the map
            max_len=max(max_len,i-mp[cum_sum]);
        }
        else{
            mp[cum_sum]=i;
        }
    }
    cout<<"Max length: "<<max_len;
}
using namespace std;
int main(){
    int arr[]={1,0,0,1,0,0,1,1,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    firstApproch(arr,n);
    cout<<endl;
    secondApproch(arr,n);
    return 0;
}