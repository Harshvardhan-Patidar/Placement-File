// Reverse the linked list in the perticular interval which is given by user

#include <bits/stdc++.h>
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
void traverse(node *head){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
node *reverse(int k,node *head){
    if(head==NULL){
        cout<<"No linked list is created";
    }
    node *next=NULL;
    node *prev=NULL;
    node *current=head;
    int count=0;
    while(current!=NULL && count<k){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;
    }
    if(next!=NULL){
        head->next=reverse(k,next);
    }
    return prev;
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);
    create(6);
    create(7);
    cout<<"Before reverse: ";
    traverse(head);
    cout<<endl;
    node *newHead=reverse(3,head);
    cout<<"After reverse: ";
    traverse(newHead);
    return 0;
}