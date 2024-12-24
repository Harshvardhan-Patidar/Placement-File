// Two linked list is given, our task is to firstly reverse the LL then add both then reverse the result end at last create a LL of result.

#include <iostream>
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
void add(node **head1,node **head2){
    node *n1=*head1;
    node *n2=*head2;
    node *result=NULL;
    node *tail=NULL;
    int carry=0,sum=0;
    while(n1!=NULL || n2!=NULL){
        int a,b;
        if(n1==NULL) a=0;
        else a=n1->data;
        if(n2==NULL) b=0;
        else b=n2->data;

        sum=a+b+carry;
        carry=sum/10;
        sum=sum%10;
        create(sum,&result);

        if(n1!=NULL) n1=n1->next;
        if(n2!=NULL) n2=n2->next;
    }
    if(carry>0){
        create(carry,&result);
    }
    cout<<"Added linked list: ";
    traverse(result);
}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    cout<<"First linked list: ";
    create(8,&head1);
    create(5,&head1);
    create(2,&head1);
    create(1,&head1);
    traverse(head1);
    cout<<endl;
    cout<<"Second linked list: ";
    create(9,&head2);
    create(2,&head2);
    create(7,&head2);
    create(1,&head2);
    traverse(head2);
    cout<<endl;
    add(&head1,&head2);
    return 0;
}