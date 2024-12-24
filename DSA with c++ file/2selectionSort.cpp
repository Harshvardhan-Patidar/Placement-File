#include <iostream>
using namespace std;
void selectionSort(int arr[],int n){
    int less_value,temp;
    for(int i=0;i<n-1;i++){
        less_value = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[less_value]){
                less_value=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[less_value];
        arr[less_value]=temp;
    }
}
int main(){
    int arr[5]={0,4,3,2,1};
    selectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}