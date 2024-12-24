#include <iostream>
using namespace std;
int top=-1, stack[10];

void push(int value,int size){
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    top++;
    stack[top]=value;
    cout<<"Pushed: "<<value<<endl;
}
void pop(){
    if(top==-1){
        cout<<"Stack empty"<<endl;
        return;
    }
    cout<<"Poped: "<<stack[top]<<endl;
    top--;
}
void peek(){
    int peeked=stack[top];
    cout<<"Peeked: "<<peeked<<endl;
}
int main(){
    int size=10;
    push(18,size);
    push(3,size);
    push(2004,size);
    pop();
    peek();
    return 0;
}