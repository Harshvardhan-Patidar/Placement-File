// Task is two find the intersection between two different linkd list

#include <iostream>
using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
};
node *head1=NULL;
node *head2=NULL;
void create1(int data){
    node *newnode=new node();
    node *ptr;
    newnode->data=data;
    if(head1==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        head1=newnode;
        ptr=head1;
        return;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
    ptr=newnode;
}
void traverse1(){
    node *ptr=head1;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void create2(int data){
    node *newnode=new node();
    node *ptr;
    newnode->data=data;
    if(head2==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        head2=newnode;
        ptr=head2;
        return;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
    ptr=newnode;
}
void traverse2(){
    node *ptr=head2;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void intersect(){
    node *p1=head1;
    node *p2=head2;
    for(int i=0;i<2;i++){
        p1=p1->next;
    }
    while(p2->next!=NULL){
        p2=p2->next;
    }
    p2->next=p1;
}
void firstApproch(){
    int a=false;
    node *p=head1;
    node *q=head2;
    while(p!=NULL){
        while(q!=NULL){
            if(p==q){
                cout<<"Intersection present om: "<<p->data;
                a=true;
                return;
            }
            q=q->next;
        }
        p=p->next;
        q=head2;
    }
    if(a==false){
        cout<<"No intersection";
    }
}
void secondApproch(){
    node *p=head1;
    node *q=head2;
    int l1=0,l2=0;
    while(p!=NULL){
        l1++;
        p=p->next;
    }
    while(q!=NULL){
        l2++;
        q=q->next;
    }
    p=head1;
    q=head2;
    int d=abs(l1-l2);
    if(l1>=l2){
        for(int i=1;i<d;i++){
            p=p->next;
        }
    }
    else{
        for(int i=1;i<d;i++){
            q=q->next;
        }
    }
    do{
        if(p==q){
            cout<<"Intersection exist";
            return;
        }
        p=p->next;
        q=q->next;
    }while(p->next!=NULL);
    if(p!=q){
        cout<<"No intersection";
    }
}

int main(){
    create1(0);
    create1(1);
    create1(2);
    create1(3);
    create1(4);
    cout<<"Linked List 1: ";
    traverse1();
    create2(5);
    create2(6);
    cout<<endl;
    cout<<"Linked List 2: ";
    traverse2();
    intersect();   // it intersect the linked list
    cout<<endl;
    // firstApproch();
    secondApproch();
    return 0;
}