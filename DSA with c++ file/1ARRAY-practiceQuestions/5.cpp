// An array is given check in the array, sum of subarray is zero or not

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n,int sum){
    int count=0;
    for(int i=0;i<n;i++){
        int j=i;
        for(j-i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                count++;
            }
        }
    }
    cout<<"Subarray present are: "<<count;
}

void secondApproch(int arr,int n,int sum){
    unordered_map<int,int> mp;
    int count=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            count++;
        }
        else{
            if(mp[sum]>0){
                count++;
            }
            else{
                mp[sum]++;
            }
        }
    }
    cout<<"Subarray present are: "<<count;
}
int main(){
    int arr[]={1,2,3,-6,2,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    firstApproch(arr,n,sum);
    cout<<endl;
    secondApproch(arr,n,sum);
    return 0;
}