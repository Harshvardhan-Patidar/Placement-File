// we have given sum and array. our task to find the three pair which addition is equal to sum

#include <bits/stdc++.h>
using namespace std;
void firstApproch(int arr[],int sum,int n){
        for(int i=0;i<n;i++){
        for(int j=1;i<n;j++){
            for(int k=2;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==sum){
                    cout<<arr[i]<<" + "<<arr[j]<<" + "<<arr[k]<<" = "<<sum<<endl;
                }
            }
        }
    }
}

void secondApproch(int arr[],int sum,int n){
        for(int i=0;i<n;i++){
        int first=i+1;
        int last=n-1;
        while(first<last){
            if(arr[i]+arr[first]+arr[last]==sum){
                cout<<arr[i]<<" + "<<arr[first]<<" + "<<arr[last]<<" = "<<sum<<endl;
                first++;
                last++;
            }
            else if(arr[i]+arr[first]+arr[last]<sum){
                first++;
            }
            else{
                last--;
            }
        }
    }
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int sum=10;
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    firstApproch(arr,sum,n);
    cout<<endl;
    secondApproch(arr,sum,n);
    return 0;
}