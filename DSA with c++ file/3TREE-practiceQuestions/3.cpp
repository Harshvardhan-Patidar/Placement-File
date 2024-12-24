// Print all boundary node of the tree

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
void leftTraversl(node *p,vector<int> &ans){
    if(p==NULL){
        return;
    }
    if(p->left->left!=NULL){
        ans.push_back(p->left->data);
        leftTraversl(p->left,ans);
    }
    else if(p->right->right!=NULL){
        ans.push_back(p->right->data);
        leftTraversl(p->right,ans);
    }
}
void leafTraversal(node *p,vector<int> &ans){
    if(p==NULL){
        return;
    }
    leafTraversal(p->left,ans);
    if(p->left==NULL && p->right==NULL){
        ans.push_back(p->data);
    }
    leafTraversal(p->right,ans);
}
void rightTraversal(node *p,vector<int> &ans){
    if(p==NULL){
        return ;
    }
    if(p->right!=NULL){
        rightTraversal(p->right,ans);
        ans.push_back(p->data);
    }
    else if(p->left!=NULL){
        rightTraversal(p->left,ans);
        ans.push_back(p->data);
    }
}
void boundary(){
    vector<int> ans;
    ans.push_back(root->data);
    leftTraversl(root,ans);
    leafTraversal(root,ans);
    rightTraversal(root,ans);
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(1);
    boundary();
    return 0;
}