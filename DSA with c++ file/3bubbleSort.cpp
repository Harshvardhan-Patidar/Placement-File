#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    int temp;
    bool stop;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                stop=true;
            }
        }
        if(stop==false){
            break;
        }
    }
}
int main(){
    int arr[5]={5,4,3,2,1};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}