// Inserting node at end of the circular linked list

#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=NULL;
void create(int data){
    node *newnode=new node();
    node *ptr;
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        head->next=head;
        ptr=head;
        return;
    }
    ptr->next=newnode;
    newnode->next=head;
    ptr=newnode;
}
void traverse(){
    node *ptr=head;
    while(ptr->next!=head){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
}
void insert(int data){
    if(head==NULL){
        cout<<"Firstly call the create() funtion"<<endl;
    }
    node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    node *newnode=new node();
    newnode->data=data;
    ptr->next=newnode;
    newnode->next=head;
    ptr=newnode;
}
int main(){
    create(1);
    create(2);
    create(3);
    cout<<"Before Intsering: ";
    traverse();
    insert(4);
    insert(5);
    cout<<"After Inserting: ";
    traverse();
    return 0;
}