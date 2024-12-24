//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;

int sum_ofarray(*arr,n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=*(arr+i);    //sum+=arr[i]
    }
    return sum;
}

void change_variable(*n1){
    *(n1)=58;
}
int main(){
    int arr=[0,1,2,3,4,5];
    cout<<sum_ofarray(arr,6);
    int n=21;
    change_variable(&n);
    return 0;
}