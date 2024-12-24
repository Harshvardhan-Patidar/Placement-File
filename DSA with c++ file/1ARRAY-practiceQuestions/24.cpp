// An array is given, an two elements of array for an container our task to find whch container store more water
#include <bits/stdc++.h>
using namespace std;
void firstApproch(int a[],int n){
    int tMax,max=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]<=a[j]){
                tMax=(a[i]*(j-i));
                if(tMax>max){
                    max=tMax;
                }
            }
            else{
                tMax=(a[j]*(abs(i-j)));
                if(tMax>max){
                    max=tMax;
                }
            }
        }
        tMax=0;
    }
    cout<<"Max water contains: "<<max;
}
void secondApproch(int a[],n){
    cout<<endl;
    int left=0,right=n-1;
    int max=0,tmax;
    while(left<=right){
        tmax=(min(a[left],a[right])*(right-left));
        if(a[left]<=a[right]){
            left++;
        }
        else if(a[right]<a[left]){
            right--;
        }
        if(tmax>max){
            max=tmax;
        }
    }
    cout<<"Max water contains: "<<max;
}
int main(){
    int a[]={1,8,6,2,5,4,8,3,7};
    int n=sizeof(a)/sizeof(a[0]);
    // firstApproch(a,n);
    secondApproch(a,n);
    return 0;
}