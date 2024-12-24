// Task is to print all path to leaf node

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
void leafPath(node *p,int arr[],int len){
    if(p==NULL){
        return;
    }
    arr[len]=p->data;
    len++;
    if(p->left==NULL && p->right==NULL){
        for(int i=0;i<len;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    leafPath(p->left,arr,len);
    leafPath(p->right,arr,len);
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(1);
    int arr[10];
    leafPath(root,arr,0);
    return 0;
}