// we have given sum and array. our task to find the two pair which addition is equal to sum

#include <bits/stdc++.h>
using namespace std;
void firstApproch(int arr[],int sum){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i]+arr[j]==sum){
                cout<<arr[i]<<" + "<<arr[j]<<" = "<<sum<<endl;
            }
        }
    }
}

void secondApproch(int arr[],int sum){
    int first=0,last=4;
    while(first<=last){
        int add=arr[first]+arr[last];
        if(add==sum){
            cout<<arr[first]<<" + "<<arr[last]<<" = "<<sum<<endl;
            first++;
            last--;
        }
        else if(add<sum){
            first++;
        }
        else{
            last--;
        }
    }
}

int main(){
    int arr[]={9,2,8,4,5};
    sort(arr,arr+5);
    int sum=7;
    cout<<"numbers: "<<endl;
    firstApproch(arr,sum);
    cout<<endl;
    secondApproch(arr,sum);
    return 0;
}