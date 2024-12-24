// Task to find the longest comman prefix string

#include <bits/stdc++.h>
using namespace std;
void firstApproch(string a[],int n){
    string res=a[0];
    string temp="";
    for(int i=1;i<n;i++){
        temp="";
        for(int j=0;j<res.length() && j< a[i].length();j++){
            if(a[i][j]==res[j]){
                temp=temp+a[i][j];
            }
            else{
                break;
            }
        }
        res=temp;
    }
    cout<<"Longest string: "<<temp;
}
void secondApproch(int a[],int n){
    sort(a,a+n);
    string temp="";
    for(int i=0;i<a[n-1].length() && i<a[0].length();i++){
        if(a[0][i]==a[n-1][i]){
            temp=temp+a[0][i];
        }
        else{
            break;
        }
    }
    cout<<temp;
}
int main(){
                // 2        1       3         4            after sorting
    string a[]={"harsh","harish","harshu","harshita"};
    int n=sizeof(a)/sizeof(a[0]);
    firstApproch(a,n);
    secondApproch(a,n);
    return 0;
}