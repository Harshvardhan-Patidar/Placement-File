// Our task is to check that the another tree is the subtree of main tree or not

#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
};
node *root=NULL;
node *root1=NULL;
node *createNode(int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
bool similer(node *r,node *s){
    if(r==NULL && s==NULL){
        return r==NULL && s==NULL;
    }
    else if(r->data==s->data){
        return similer(r->left,s->left) && similer(r->right,s->right);
    }
    return false;
}
bool subTree(node *root,node *subRoot){
    if(root==NULL){
        return false;
    }
    else if(similer(root,subRoot)){
        return true;
    }
    return subTree(root->left,subRoot) || subTree(root->right,subRoot);
}
int main(){
    root=createNode(10);
    root->left=createNode(8);
    root->right=createNode(2);
    root->left->left=createNode(3);
    root->left->right=createNode(5);
    root->right->left=createNode(1);
    root1=createNode(8);
    root1->left=createNode(3);
    root1->right=createNode(5);
    if(subTree(root,root1)){
        cout<<"Tree 2 is the subtree of tree 1";
    }
    else{
        cout<<"Tree 2 is not a subtree";
    }
    return 0;
}