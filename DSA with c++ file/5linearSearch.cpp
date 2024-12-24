#include <iostream>
using namespace std;
int linearSearch(int arr[],int n,int value){
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int value;
    cout<<"Enter Number: ";
    cin>>value;
    if(linearSearch(arr,6,value)){
        cout<<"Founded!!";
    }
    else{
        cout<<"Not Found??";
    }
    return 0;
}