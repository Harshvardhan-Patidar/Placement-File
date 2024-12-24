#include <bits/stdc++.h>
using namespace std;
int front=-1,rear=-1,Queue[10];
void enqueue(int size,int data){
    if(rear==size-1){
        cout<<"Queue is full"<<endl;
        return;
    }
    if(rear==-1 && front==-1){
        rear=0;
        front=0;
    }
    else{
        rear++;
    }
    Queue[rear]=data;
    cout<<"Enqueue: "<<Queue[rear]<<endl;
}
void dequeue(){
    if(front==-1 && front>rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Dequeued: "<<Queue[front]<<endl;
    front++;
    if(front==rear){
        front=rear=-1;
        return
    }
}
void peek(int size){
    if(front==-1 && front>rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Peeked: "<<Queue[front];
}
int main(){
    int size=10;
    enqueue(size,1);
    enqueue(size,2);
    enqueue(size,3);
    enqueue(size,4);
    dequeue();
    peek(size);
    return 0;
}