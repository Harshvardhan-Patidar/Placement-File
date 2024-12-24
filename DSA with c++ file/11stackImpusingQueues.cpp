#include <bits/stdc++.h>
using namespace std;
class stack{
    public:
    queue<int> q1,q2;
    int size;
    stack(){
        size=0;
    }
    void push(int data){
        size++;
        q2.push(data);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    queue<int> temp;
    temp=q1;
    q1=q2;
    q2=temp;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
        size--;
    }
    int peek(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
}s;
int main(){
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"Size of stack: "<<s.size;
    cout<<s.peek()<<endl;
    s.pop();
    cout<<"After Pop size of stack: "<<s.size<<endl;
    return 0;
}