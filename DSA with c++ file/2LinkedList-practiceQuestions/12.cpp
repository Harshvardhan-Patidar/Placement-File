// Delete the Nth node without using the head pointer(without head pointer implemantation)

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
//we doesnot use head just only refrence to delete node

void deleteN(node *deletenode){
    if(deletenode==NULL){
        cout<<"No Node is present";
        return;
    }
    if(deletenode->next==NULL){
        cout<<"Last node delete permission is not given";
        return;
    }
    deletenode->data=deletenode->next->data;
    node *temp=deletenode->next;
    deletenode->next=temp->next;
    delete temp;
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);
    cout<<"Before delete: ";
    traverse();
    cout<<endl;
    cout<<"After delete: ";
    node * deletenode=head->next->next;
    deleteN(deletenode);
    traverse();
    return 0;
}