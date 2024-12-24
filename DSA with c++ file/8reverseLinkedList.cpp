#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
void createNode(node **head,int data){
    node *newnode = new node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void traverse(node *ptr){
    if(ptr==NULL){
        return;
    }
    else{
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    cout<<endl;
}
void reverse(node **head){
    node *prev=NULL,*current=*head,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
int main(){
    node *head = NULL;
    createNode(&head,1);
    createNode(&head,2);
    createNode(&head,3);
    createNode(&head,4);
    createNode(&head,5);
    traverse(head); 
    reverse(&head);
    traverse(head);
    return 0;
}