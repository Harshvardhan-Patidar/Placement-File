// Our task is to find the smallest positive missing number

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[0]>2){
            cout<<"Smallest positive number: 1";
            break;
        }
        if(arr[i]>=0){
            if(arr[i]==arr[i+1]-1){
                continue;
            }
            else{
                cout<<"Smallest positive number: "<<arr[i]+1;
                break;
            }
        }
    }
}
void secondApproch(int arr[],int n){
    int number=1, a=0,flag=0;
    while(a==0){
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(arr[i]==number){
                flag=1;
                break;
            }
        }
        if(flag==1){
            number++;
        }
        else{
            a=1;
            break;
            cout<<"Smallest positive number: "<<number;
        }
    }
}
void thirdApproch(int arr[],int n){
    int number=1;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(a[i]>0){
            if(a[i]=number){
                number++;
            }
            else{
                cout<<"Smallest positive number: "<<number;
            }
        }
    }
}
int main(){
    int arr[]={4,-3,-6,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    // firstApproch(arr,n);
    // secondApproch(arr,n);
    // thirdApproch(arr,n);
    return 0;
}