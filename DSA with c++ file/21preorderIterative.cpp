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
void preorder(){
    if(root==NULL){
        return;
    }
    stack<node*> s;
    node *current=root;
    s.push(current);
    while(s.empty()==false){
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        if(current->right!=NULL){
            s.push(current->right);
        }
        if(current->left!=NULL){
            s.push(current->left);
        }
    }
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    preorder();
    return 0;
}