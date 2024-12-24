// Task is to merge the two interval if first interval second element is greater than second interval first element
// eg.  [[1,4],[2,6],[7,10]]  ->  [[1,6],[7,10]]

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> intervals;    // A 2D vector
    int f,s,n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> interval;
        cin>>f>>s;
        interval.push_back(f);
        interval.push_back(s);
        intervals.push_back(interval);
    }
    vector<int> temp;
    vector<vector<int>> result;
    sort(intervals.begin(),intervals.end());
    temp=intervals[0];
    for(auto i: intervals){
        if(temp[1]>=i[0]){
            temp[1]=max(i[1],temp[1]);
        }
        else{
            result.push_back(temp);
            temp=i;
        }
    }
    result.push_back(temp);
    cout<<"[";
    for(auto i:result){
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    }
    cout<<"]";
    return 0;
}