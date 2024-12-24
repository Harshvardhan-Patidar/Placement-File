// To find the contiguous subarray of given length k that has the maximum average value

#include <bits/stdc++.h>
using namespace std;
void firstApproch(int arr[],int n,double average){
    int sum=0;
    double maxSum=arr[0];
    for(int i=0;i<n;i++){
        int a=1;
        for(int j=i;j<n;j++){                                                                                                                  
            if(a>average){
                break;
            }
            a++;
            sum+=arr[j];
            if(sum>maxSum){
                maxSum=sum;
            }
        }
        if(arr[n-3]==arr[i]){break;}
        sum=0;
    }
    double avg=maxSum/average;
    cout<<"Max average: "<<avg;
}
void secondApproch(int a[],int n,double k){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    int maxSum=sum;
    int j,i=0;
    for(j=k;j<n;j++){
        sum=sum-a[i]+a[j];
        maxSum=max(sum,maxSum);
        i++;
    }
    cout<<"Max average: "<<maxSum/k;
}
int main(){
    int arr[]={1,12,-5,-6,50,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int average=4;
    firstApproch(arr,n,4);
    cout<<endl;
    secondApproch(arr,n,4);
    return 0;
}