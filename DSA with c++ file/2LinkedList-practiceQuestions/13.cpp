// Task is to swaping the node pairwise

#include <iostream>
using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
};
node *head=NULL;
void create(int data){
    node *newnode=new node();
    node *ptr;
    newnode->data=data;
    if(head==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        ptr=head;
        return;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
    ptr=newnode;
}
void traverse(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void swap(){
    if(head==NULL){
        cout<<"No linked list present";
        return;
    }
    node *p=head;
    node *q=p->next;
    int temp;
    cout<<"After swap: ";
    while(q!=NULL && p->next!=NULL){
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        cout<<p->data<<" "<<q->data<<" ";
        p=p->next->next;
        q=q->next->next;
    }
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    cout<<"Before swap: ";
    traverse();
    cout<<endl;
    swap();
    return 0;
}