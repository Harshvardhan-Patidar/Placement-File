#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
node *rear=NULL;
node *front=NULL;
void enqueue(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->next=rear;
    rear=newnode;
    cout<<"Equeue: "<<newnode->data<<endl;
    if(rear->next==NULL){
        front=rear;
    }
}
void dequeue(){
    if(rear==NULL && front==NULL){
        cout<<"No data"<<endl;
    }
    node *temp=rear;
    while(temp->next!=front){
        temp=temp->next;
    }
    cout<<"Dequeue: "<<front->data<<endl;
    delete front;
    front=temp;
    front->next=NULL;
}
void peek(){
    if(rear==NULL && front==NULL){
        cout<<"No data"<<endl;
        return;
    }
    cout<<"Peeked: "<<front->data<<endl;
}
void traverse(){
    node *ptr=rear;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    dequeue();
    peek();
    traverse();
    return 0;
}