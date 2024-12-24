// Create a doubly linked list and add the node at the end of the list

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
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    traverse();
    return 0;
}