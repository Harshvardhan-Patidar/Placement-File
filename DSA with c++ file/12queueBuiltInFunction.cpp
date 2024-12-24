#include <bits/stdc++.h>
using namespace std;
void show(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"Our queue: "<<endl;
    show(q);
    return 0;
}