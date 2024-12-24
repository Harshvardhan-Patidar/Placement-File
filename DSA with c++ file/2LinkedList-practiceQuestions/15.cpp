// Task is to remove duplicates from unsorted linked list

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
void traverse(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void firstApproch(){
    if(head==NULL){
        cout<<"No output";
    }
    node *p=head;
    node *q=p->next;
    node *temp=head;
    cout<<"After delete: ";
    while(p->next!=NULL){
        cout<<p->data<<" ";
        while(q!=NULL){
            if(p->data==q->data){
                temp->next=q->next;
                delete q;
                q=temp->next;
            }
            else{
                q=q->next;
                temp=temp->next;
            }
        }
        p=p->next;
        q=p->next;
        temp=p;
    }
}
void secondApproch(){
    if(head==NULL){
        cout<<"No output";
        return;
    }
    node *p=head;
    node *prev=NULL;
    unordered_set<int> st;
    while(p!=NULL){
        if(st.find(p->data)!=st.end()){
            prev->next=p->next;
            node *temp=p;
            p=p->next;
            delete temp;
        }
        else{
            st.insert(p->data);
            prev=p;
            p=p->next;
        }
    }
}
int main(){
    create(1);
    create(2);
    create(2);
    create(3);
    create(4);
    create(4);
    cout<<"Before delete: ";
    traverse();
    cout<<endl;
    // firstApproch();
    secondApproch();
    cout<<"After delete: ";
    traverse();
    return 0;
}