// Task is to check that given linked list is palindrome or not

#include <bits/stdc++.h>
#include <string>
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
bool firstApproch(){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }
    string str="";
    node *p=head;
    while(p!=NULL){
        str=str+to_string(p->data);
        p=p->next;
    }
    string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}
bool secondApproch(){
    node *slow=head;
    node *fast=head;
    node *prevSlow=head;
    node *second=NULL;           // it is 2nd part of LL
    if(head!=NULL && head->next!=NULL){
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prevSlow=slow;
            slow=slow->next;
        }
        if(fast!=NULL){
            second=slow->next;
        }
        else{
            second=slow;
        }
        node *next=NULL;
        node *prev=NULL;
        node *current=second;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        second=prev;
        slow=head;
        while(second!=NULL){
            if(second->data!=slow->data){
                return false;
            }
            second=second->next;
            slow=slow->next;
        }
    }
    return true;
}
int main(){
    create(1);
    create(2);
    create(2);
    create(1);
    traverse();
    cout<<endl;
    if(secondApproch()){
        cout<<"Given linked list is palindrome";
    }
    else{
        cout<<"Given linked list is not palindrome";
    }
    return 0;
}