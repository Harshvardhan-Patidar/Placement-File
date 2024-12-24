// Delete head node from the circular linked list

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
void deleteHead(){
    if(head==NULL){
        cout<<"No Node is present to delete"<<endl;
        return;
    }
    if(head=head->next){
        head=NULL;
        return;
    }
    node *ptr=head;
    node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    head=head->next;
    p->next=head;
    delete ptr;
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    cout<<"Before Deleting Head: ";
    traverse();
    deleteHead();
    cout<<"After Deleting Head: ";
    traverse();
}