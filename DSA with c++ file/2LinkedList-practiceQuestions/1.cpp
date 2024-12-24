// Task is to delete the Nth node, starting from the end of the linked list
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=NULL;
int num=0;
void create(int data){
    node *newnode = new node();
    newnode->data=data;
    newnode->next=NULL;
    num++;
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
node* deleteNth(){
    int n,i=1;
    cout<<"Enter the Nth number(from end): "<<endl;
    cin>>n;
    int j=num-n;
    node *p1=head;
    node *p2=p1->next;
    while(i!=j){
        p1=p1->next;
        p2=p2->next;
        i++;
    }
    if(p2->next==NULL){
        p1->next=NULL;
        delete p2;
        return head;
    }
    p1->next=p2->next;
    delete p2;
    return head;
}

int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    cout<<"Before Deleting:"<<endl;
    traverse();
    cout<<endl;
    head = deleteNth();
    cout<<"After Deleting:"<<endl;
    traverse();
    return 0;
}