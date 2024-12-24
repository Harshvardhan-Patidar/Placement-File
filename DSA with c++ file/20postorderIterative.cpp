#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
};
node *root=NULL;
node *newNode(int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void postorder(){
    if(root==NULL){
        return;
    }
    stack<node*> s1;
    stack<node*> s2;
    node *current=root;
    s1.push(current);
    while(s1.empty()==false){
        current=s1.top();
        s1.pop();
        s2.push(current);
        if(current->left!=NULL){
            s1.push(current->left);
        }
        if(current->right!=NULL){
            s1.push(current->right);
        }
    }
    while(s2.empty()==false){
        cout<<s2.top()->data<<" ";     //current=s2.pop();
        s2.pop();                      //cout<<current->data;
    }
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    postorder();
    return 0;
}