// Task is tofind the index of the given rotated array

#include <iostream>
using namespace std;
void firstApproch(int arr[],int n,int value){
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            cout<<"Index of given element is: "<<i;
            break;
        }
    }
}
void secondApproch(int arr[],int n,int value){
    int pivot=0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i+1]){
        }
        else{
            pivot=i;
        }
    }
    if(value<arr[pivot] && value>arr[0]){
        for(int i=0;i<n;i++){
            int first=0,last=pivot,mid=first+last/2;
            if(arr[mid]==value){
                cout<<"Index of given element is: "<<mid;
                break;
            }
            else if(arr[mid]<value){
                first=mid+1;
            }
            else{
                pivot=mid-1;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            int first=pivot,last=n,mid=first+last/2;
            if(arr[mid]==value){
                cout<<"Index of given element is: "<<mid;
                break;
            }
            else if(arr[mid]<value){
                pivot=mid+1;
            }
            else{
                last=mid-1;
            }
        }
    }
}
int main(){
    int arr[]={4,5,6,7,8,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    // firstApproch(arr,n,5);
    cout<<endl;
    secondApproch(arr,n,6);
    return 0;
}