#include <iostream>
using namespace std;
int binarySearch(int arr[],int first,int last,int value){
    int mid;
    if(last>=first){
    mid=(first+last)/2;
    if(arr[mid]==value){
        return mid+1;
    }
    else if(arr[mid]<value){
        return binarySearch(arr,mid+1,last,value);
    }
    else{
        return binarySearch(arr,first,mid-1,value);
    }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int result=binarySearch(arr,0,5,5);
    if(result==-1){
        cout<<"Not Found??";
    }
    else{
        cout<<"Founded at "<<result<<" position";
    }
    return 0;
}