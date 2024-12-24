// Task is to merge tow sorted array in third array in sorted form

#include <bits/stdc++.h>
using namespace std;
void firstApproch(int arr1[],int arr2[],int arr3[],int n,int m){
    int j=0;
    for(int i=0;i<n+m;i++){
        if(i<n){
            arr3[i]=arr1[i];
        }else{
            arr3[i]=arr2[j];
            j++;
        }
    }
    sort(arr3,arr3+n+m);
    for(int i=0;i<n+m;i++){
        cout<<arr3[i]<<" ";
    }
}
void secondApproch(int a1[],int a2[],int a3[],int n,int m){
    int k=0;
    int i=0,j=0;
    while(i<n || j<m){
        if(a1[i]<a2[j]){
            a3[k]=a1[i];
            k++;
            i++;
        }
        else{
            a3[k]=a2[j];
            k++;
            j++;
        }
    }
    while(i<n){
        a3[k]=a1[i];
        k++;
        i++;
    }
    while(j<m){
        a3[k]=a2[j];
        k++;
        j++;
    }
    for(int x=0;x<n+m;x++){
        cout<<a3[x]<<" ";
    }
}
int main(){
    int arr1[]={6,8,10};
    int arr2[]={4,5,7,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n+m];
    int j=0;
    firstApproch(arr1,arr2,arr3,n,m);
    cout<<endl;
    secondApproch(arr1,arr2,arr3,n,m);
    return 0;
}