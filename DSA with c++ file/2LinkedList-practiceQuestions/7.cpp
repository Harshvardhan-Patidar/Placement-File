// Create a doubly linked list and add the node at the starting of the linked list

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
void insertAtStart(int data){
    if(head==NULL){
        cout<<"Firstly call the create() funtion to create a linked list"<<endl;
        return;
    }
    node *ptr=head;
    node *newnode=new node();
    newnode->data=data;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
    head->next=ptr;
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    cout<<"Before inserting at starting: ";
    traverse();
    cout<<endl;
    cout<<"After inserting at starting: ";
    insertAtStart(0);
    traverse();
    return 0;
}