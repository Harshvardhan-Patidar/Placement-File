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
int maxValue(node *root){
    if(root==NULL){
        return INT_MIN;
    }
    node *p=root;
    int result=p->data;
    int Lresult=maxValue(p->left);
    int Rresult=maxValue(p->right);
    return max({result,Lresult,Rresult});
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    cout<<"Maximum value in Binary Tree: "<<maxValue(root);
    return 0;
}