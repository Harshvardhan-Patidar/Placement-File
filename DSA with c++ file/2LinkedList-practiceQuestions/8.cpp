// Deleting the head node from the doubly linked list
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
void deleteHead(){
    if(head==NULL){
        cout<<"No linked list is present"<<endl;
        return;
    }
    if(head->next==NULL){
        node *temp=head;
        head=NULL;
        delete temp;
    }
    node *ptr=head;
    head=head->next;
    head->prev=NULL;
    delete ptr;
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    cout<<"Before Deleting: ";
    traverse();
    cout<<endl;
    cout<<"After Deleting: ";
    deleteHead();
    traverse();
    return 0;
}