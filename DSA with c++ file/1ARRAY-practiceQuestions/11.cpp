// we have an input value, our task is to find the index of that element from the first

#include <iostream>
using namespace std;

void firstApproch(int arr[],int n,int value){
        for(int i=0;i<n;i++){
        if(arr[i]==value){
            cout<<"Element occure at index: "<<i;
            break;
        }
    }
}

void secondApproch(int arr[],int n,int value){
    int first=0,last=n-1,mid,firstOccure;
    while(first<=last){
        mid=(first+last)/2;
        if(arr[mid]==value){
            firstOccure=mid;
            last=mid-1;
        }
        else if(arr[mid]<value){
            first=mid+1;
        }
        else if(arr[mid]>value){
            last=mid-1;
        }
    }
    cout<<"Element occure at index: "<<firstOccure;
}
int main(){
    int arr[]={3,6,6,7,9,9,9,12,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int value;
    cin>>value;
    cout<<endl;
    firstApproch(arr,n,value);
    cout<<endl;
    secondApproch(arr,n,value);
    return 0;
}