// Our task is to mer#include <iostream>
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
void firstApproch(node **head1,node **head2){
    node *p=*head1;
    node *q=*head2;
    if(p==NULL && q==NULL){
        cout<<"No linked list exixt";
        return;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    p=*head1;
    q=p->next;
    while(p->next!=NULL){
        while(q!=NULL){
            if(p->data>=q->data){
                swap(p->data,q->data);
            }
            q=q->next;
        }
        p=p->next;
        q=p->next;
    }
}
void secondApproch(node **head1,node **head2){
    node *head3=NULL;
    node *p=*head1;
    node *q=*head2;
    while(p!=NULL && q!=NULL){
        if(p->data>=q->data){
            create(q->data,&head3);
            q=q->next;
        }
        else{
            create(p->data,&head3);
            p=p->next;
        }
    }
    if(p!=NULL){
        while(p!=NULL){
            create(p->data,&head3);
            p=p->next;
        }
    }
    if(q!=NULL){
        while(q!=NULL){
            create(q->data,&head3);
            q=q->next;
        }
    }
    traverse(head3);
}
void thirdApproch(node **head1,node **head2){
    node *newHead;
    node *p=*head1;
    node *q=*head2;
    if(p->data<q->data){
        newHead=*head1;
        p=newHead->next;
        q=*head2;
    }
    else{
        newHead=*head2;
        p=*head1;
        q=newHead->next;
    }
    node *temp=newHead;
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            temp->next=p;
            p=p->next;
            temp=temp->next;
        }
        else{
            temp->next=q;
            q=q->next;
            temp=temp->next;
        }
    }
    if(p==NULL){
        temp->next=q;
    }
    else{
        temp->next=p;
    }
    traverse(newHead);
}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    cout<<"First linked list: ";
    create(1,&head1);
    create(3,&head1);
    create(5,&head1);
    create(8,&head1);
    traverse(head1);
    cout<<endl;
    cout<<"Second linked list: ";
    create(2,&head2);
    create(4,&head2);
    create(6,&head2);
    create(7,&head2);
    traverse(head2);
    cout<<endl;
    cout<<"Merge linked list: ";
    // firstApproch(&head1,&head2);
    // traverse(head1);
    // secondApproch(&head1,&head2);
    thirdApproch(&head1,&head2);
    return 0;
}