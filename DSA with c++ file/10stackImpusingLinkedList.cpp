#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void push(node **top,int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->next=*top;
    *top=newnode;
    cout<<"Pushed: "<<newnode->data<<endl;
}
void pop(node **top){
    node *poped=*top;
    if(poped==NULL){
        cout<<"NO";
        return;
    }
    node *temp=poped;
    poped=poped->next;
    *top=poped;
    cout<<"Poped: "<<temp->data<<endl;
    delete temp;
}
void peek(node **top){
    node *peeked=*top;
    if(peeked==NULL){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"Peeked: "<<peeked->data<<endl;
}
int main(){
    node *top=new node();
    top=NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    pop(&top);
    peek(&top);
}