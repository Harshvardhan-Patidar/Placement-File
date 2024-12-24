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
int height(node *p){
    if(p==NULL){
        return 0;
    }
    int lHeight=height(p->left);
    int rHeight=height(p->right);
    return max(lHeight,rHeight)+1;
}
int diameter(node *p){
    if(p==NULL){
        return 0;
    }
    int lHeight=height(p->left);
    int rHeight=height(p->right);
    int Ldiameter=diameter(p->left);
    int Rdiameter=diameter(p->right);
    int tNode=lHeight+rHeight+1;
    return max(tNode,max(Ldiameter,rHeight));
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->right=newNode(6);
    root->left->right->left=newNode(7);
    cout<<"Diameter of tree is: "<<diameter(root);
    return 0;
}