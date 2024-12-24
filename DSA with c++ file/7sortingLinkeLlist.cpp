#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
};

void createNode(node **head,int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
    // if(*head==NULL){
    //     *head=newnode;
    // }
    // else{
    //     node *ptr=*head;
    //     while(ptr!=NULL){
    //     ptr=ptr->next;
    //     }
    //     ptr->next=newnode;
    // }
}

void treverse(node *ptr){
    if(ptr==NULL){
        return;
    }
    while(ptr!=NULL){
        cout<<ptr->data;
        ptr=ptr->next;
        if(ptr!=NULL){
            cout<<"->";
        }
    }
    cout<<endl;
}

void firstApproch(node **head){
    node *ptr1=*head, *ptr2, *temp, *prev;
    int min;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        min=ptr1->data;
        temp=ptr1;
        prev=ptr1;
        while(prev->next!=NULL){
            if(ptr2->data<min){
                min=ptr2->data;
                temp=ptr2;
            }
            ptr2=ptr2->next;
            prev=prev->next;
        }
        min=ptr1->data;
        ptr1->data=temp->data;
        temp->data=min;
        ptr1=ptr1->next;
    }
}

void divideList(node *head,node **front,node **back){
    node *fast;
    node *slow;
    slow=head;
    fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *front=head;
    *back=slow->next;
    slow->next=NULL;
}
node *mergeDivideList(node *a,node *b){
    node *result=NULL;
    if(a==NULL) return b;
    else if(b==NULL) return a;
    if(a->data<=b->data){
        result=a;
        result->next=mergeDivideList(a->next,b);
    }
    else{
        result=b;
        result->next=mergeDivideList(a,b->next);
    }
    return result;
}
void secondApproch(node **temphead){
    node *head=*temphead;
    node *p1;
    node *p2;

    if((head==NULL) || (head->next==NULL)){
        return;
    }
    divideList(head,&p1,&p2);
    secondApproch(&p1);
    secondApproch(&p2);

    *temphead=mergeDivideList(p1,p2);
}
int main(){
    node *head= new node();
    head=NULL;
    createNode(&head,5);
    createNode(&head,8);
    createNode(&head,3);
    createNode(&head,1);
    createNode(&head,4);
    cout<<"Unsorted linked list: ";
    treverse(head);

    firstApproch(&head);
    // secondApproch(&head);

    cout<<"Sorted linked list: ";
    treverse(head);
}