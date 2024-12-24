// Add the node in begining of the circular linked list

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
    node *newnode=new node();
    newnode->data=data;
    node *ptr=head->next;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    newnode->next=head;
    head=newnode;
    ptr->next=head;
}
int main(){
    create(2);
    create(2);
    create(3);
    create(4);
    cout<<"Before Inserting: ";
    traverse();
    insert(1);
    insert(0);
    cout<<"After Inserting: ";
    traverse();
}