// Task is to check that any loop is presend in our linked list or not

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
void addLoop(){
    node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr->prev->prev;        //only randum loop will created
}
// void firstApproch(){
//     unordered_map<node*> mp;
//     node *p=head;
//     while(p!=NULL){
//         if(mp.find(p)!=mp.end()){
//             cout<<"Loop is exist"<<endl;
//             return;
//         }
//         mp.push(p);
//         p=p->next;
//     }
// }
void secondApproch(){
    node *slow=head;
    node *fast=head;
    slow=slow->next;
    fast=fast->next->next;
    if(head==NULL){
        cout<<"No linked list is exist";
        return;
    }
    while(fast!=NULL && fast->next!=NULL){
        if(slow==fast){
            cout<<"Loop Exist"<<endl;
            return;
        }
        else{
            slow=slow->next;
            fast=fast->next->next;
        }
    }
    if(slow!=fast){
        cout<<"Loop not exist";
    }
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    addLoop();
    // firstApproch();
    secondApproch();
    return 0;
}