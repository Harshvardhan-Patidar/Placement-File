// fint the present array is in equlibreium state or not means tha LHS=RHS from any index and return that index

#include <iostream>
using namespace std;
int main(){
    int arr[]={8,5,-3,2,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int totalSum=0;
    int lhsSum=0;
    for(int i=0;i<n;i++){
        totalSum=totalSum+arr[i];
    }
    for(int i=0;i<n;i++){
        totalSum=totalSum-arr[i];
        if(lhsSum==totalSum){
            cout<<"Equlibreium at: "<<i+1<<endl;
            break;
        }
        else{
            lhsSum=lhsSum+arr[i];
        }
    }
    return 0;
}