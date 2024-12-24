// find the element of the array which occure more then n/3 times

#include <bits/stdc++.h>
using namespace std;

void firstApproch(int arr[],int n,int minOccure){
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>minOccure){
            cout<<"Maximum time occure element: "<<arr[i];
            break;
        }
        count=1;
    }
        if(count<minOccure){
            cout<<"NO element with max times";
        }
}

void secondApproch(int arr[],int n,int minOccure){
    int count1=0,count2=0;
    int first=INT_MIN,second=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==first){
            count1++;
        }
        else if(arr[i]==second){
            count2++;
        }
        else if(count1==0){
            count1++;
            first=arr[i];
        }
        else if(count2==0){
            count2++;
            second=arr[i];
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==first){
            count1++;
        }
        else if(arr[i]==second){
            count2++;
        }
    }
    if(count1>minOccure){
        cout<<"Maximum time occure element: "<<first;
    }
    else if(count2>minOccure){
        cout<<"Maximum time occure element: "<<second;
    }
    else{
        cout<<"No Maximum time occure element: ";
    }
}
int main(){
    int arr[]={1,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int minOccure=n/3;
    firstApproch(arr,n,minOccure);
    cout<<endl;
    secondApproch(arr,n,minOccure);
    return 0;
}