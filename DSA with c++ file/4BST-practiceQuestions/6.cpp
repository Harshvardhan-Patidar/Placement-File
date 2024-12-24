// We want to find the Kth largest element in BST

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
node *root=NULL;
void traverse(node *root,int &i,int arr[]){
    if(root==NULL){
        return;
    }
    traverse(root->left,i,arr);
    cout<<root->data<<" ";
    arr[i]=root->data;
    i++;
    traverse(root->right,i,arr);
}
void BTtoBST(node *root,int &i,int arr[]){
    if(root==NULL){
        return;
    }
    BTtoBST(root->left,i,arr);
    root->data=arr[i];
    i++;
    BTtoBST(root->right,i,arr);
}
int main(){
    root=new node(36);
    root->left=new node(25);
    root->right=new node(20);
    root->left->left=new node(10);
    root->left->right=new node(30);
    root->left->left->left=new node(22);
    root->left->left->right=new node(40);
    root->right->left=new node(15);
    root->right->right=new node(5);
    root->right->left->left=new node(28);
    int arr[12];
    int i=0;
    cout<<"Before BST: ";
    traverse(root,i,arr);
    cout<<endl;
    sort(arr,arr+i);
    i=0;
    cout<<"After making BST: ";
    BTtoBST(root,i,arr);
    traverse(root,i,arr);
    return 0;
}