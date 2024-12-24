#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int j,holder;
    for(int i=1;i<n;i++){
        holder=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>holder){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=holder;
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    insertionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}