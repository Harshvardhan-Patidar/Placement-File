// To check tree follow children sum property or not:- the sum of child with its coresponding

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
bool child_sum_property(node *p){
    if(p==NULL || (p->left==NULL && p->right==NULL)){
        return true;
    }
    int left=0,right=0;
    if(p->left!=NULL){
        left=p->left->data;
    }
    if(p->right!=NULL){
        right=p->right->data;
    }
    if(p->data==(left+right) && (child_sum_property(p->left)) && (child_sum_property(p->right))){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(2);
    if(child_sum_property(root)){
        cout<<"Tree follow child sum property";
    }
    else{
        cout<<"Tree doesn't follow child sum property";
    }
    return 0;
}