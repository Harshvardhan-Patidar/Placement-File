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
int findHeight(node *p){
    if(p==NULL){
        return 0;
    }
    int hLeft=findHeight(p->left);
    int hRight=findHeight(p->right);
    return max(hLeft,hRight)+1;
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    // root->right->left=newNode(8);
    // root->right->right=newNode(9);
    cout<<"Height of tree is: "<<findHeight(root);
    return 0;
}