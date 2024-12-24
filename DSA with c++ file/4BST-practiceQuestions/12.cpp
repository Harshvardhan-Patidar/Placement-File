//Our task is to find the popular inorder successor.

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node *next;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
        next=NULL;
    }
};
node *root=NULL;
node *insertBST(node *root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<root->data){
        root->left=insertBST(root->left,data);
    }
    if(data>root->data){
        root->right=insertBST(root->right,data);
    }
    return root;
}
void successor(node *root,node *&pre){
    if(root==NULL){
        return;
    }
    successor(root->left,pre);
    if(pre!=NULL){
        pre->next=root;
    }
    pre=root;
    successor(root->right,pre);
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    node *pre=NULL;
    successor(root,pre);
    return 0;
}