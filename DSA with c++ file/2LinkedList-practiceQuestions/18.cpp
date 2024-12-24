// Task is to separate the odd and even(odd even are alternative)

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
};
void create(int data, node **head){
    node *newnode=new node();
    node *ptr;
    newnode->data=data;
    if(*head==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        *head=newnode;
        ptr=*head;
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
void firstApproch(node **head){
    node *p=*head;
    node *newHead1=NULL;
    node *newHead2=NULL;
    while(p!=NULL){
        if(p->data%2==0){
            create(p->data,&newHead2);
        }
        else{
            create(p->data,&newHead1);
        }
        p=p->next;
    }
    if(newHead1!=NULL){
        node *q=newHead1;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=newHead2;
    }
    else{
        newHead1=newHead2;
    }
    cout<<"After separation: ";
    traverse(newHead1);
}
void secondApproch(node **head){
    if(*head==NULL){
        cout<<"No LL";
    }
    node *odd=*head;
    node *even=odd->next;
    node *evenHead=odd->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
}
int main(){
    node *head=NULL;
    create(1,&head);
    create(2,&head);
    create(3,&head);
    create(4,&head);
    create(5,&head);
    cout<<"Before separation: ";
    traverse(head);
    cout<<endl;
    // firstApproch(&head);
    cout<<endl;
    secondApproch(&head);
    cout<<"After separation: ";
    traverse(head);
    return 0;
}