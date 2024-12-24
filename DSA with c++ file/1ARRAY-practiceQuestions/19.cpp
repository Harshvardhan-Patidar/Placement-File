// Our task is to find a longest substring without repeating characters

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="aabcde";
    int n=s.length();
    int maxLength=0;
    vector<int> mp(256,-1);
    int l=0;
    for(int i=0;i<n;i++){
        l=max(l,mp[s[i]]+1);                    
        maxLength=max(maxLength,i-l+1);        
        mp[s[i]]=i;
    }
    cout<<"Maximum length: "<<maxLength;
    return 0;
}