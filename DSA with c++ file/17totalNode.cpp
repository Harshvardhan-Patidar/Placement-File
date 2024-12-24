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
int findSize(node *p){
    if(p==NULL){
        return 0;
    }
    int sLeft=findSize(p->left);
    int sRight=findSize(p->right);
    return sLeft+sRight+1;
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    cout<<"Total number of node in tree is: "<<findSize(root);
    return 0;
}