#include <iostream>
using namespace std;
int main(){
    cout<<"Enter a number: "<<endl;
    int arr[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Array: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}