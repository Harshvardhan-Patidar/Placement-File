// Task is to find the lowest common ansester of two node

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
node *LCA(node **root,int n1,int n2){
    node *p=*root;
    if(*root==NULL){
        return NULL;
    }
    if((p->data==n1) || (p->data==n2)){
        return p;
    }
    node *leftLCA=LCA(&p->left,n1,n2);
    node *rightLCA=LCA(&p->right,n1,n2);
    if(leftLCA!=NULL && rightLCA!=NULL){
        return p;
    }
    return ((leftLCA!=NULL)?leftLCA:rightLCA);
}
int main(){
    node *root=newNode(3);
    root->left=newNode(4);
    root->right=newNode(10);
    root->left->left=newNode(5);
    root->left->right=newNode(8);
    root->right->left=newNode(6);
    root->left->right->left=newNode(15);
    cout<<"Lowest comman ansister: "<<LCA(&root,5,15)->data;
    return 0;
}