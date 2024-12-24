// Task is to delete the duplicate data from the sorted linked list

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=NULL;
void create(int data){
    node *newnode = new node();
    newnode->data=data;
    newnode->next=NULL;
    node *ptr;
    if(head==NULL){
        head=newnode;
        ptr=head;
        return;
    }
    ptr->next=newnode;
    ptr=newnode;
}
void traverse(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void deleteDuplicate(){
    node *p1=head;
    node *p2=p1->next;
    while(p1->next!=NULL){
        if((p2->next==NULL)){
            p1->next=NULL;
            delete p2;
            return;
        }
        if(p1->data==p2->data){
            p1->next=p2->next;
            delete p2;
            p2=p1->next;
        }
        if(p1->data!=p2->data){
            p1=p1->next;
            p2=p2->next;
        }
    }
}
int main(){
    create(1);
    create(1);
    create(2);
    create(3);
    create(3);
    create(3);
    create(3);
    cout<<"Before Duplicate: ";
    traverse();
    deleteDuplicate();
    cout<<endl;
    cout<<"After Removing: ";
    traverse();
    return 0;
}