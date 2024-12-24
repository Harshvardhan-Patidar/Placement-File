// draw a zig-zag patten if string

#include <bits/stdc++.h>
using namespace std;
void firstApproch(string s){
    string str1="",str2="";
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            str1=str1+s[i];
        }
        else{
            str2=str2+s[i];
        }
    }
    cout<<str1+str2;
}
int main(){
    string s="ABCDEFGH";
    firstApproch(s);
    return 0;
}