// find the subarray with maximum sum in siquence form eg below ans 9 + 3 = 13

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={3,5,-8,9,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxSum=INT_MIN,currentSum=0;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum>maxSum){
            maxSum=currentSum;
        }
        if(currentSum<0){
            currentSum=0;
        }
    }
    cout<<"Subarray max sum: "<<maxSum;
    return 0;
}