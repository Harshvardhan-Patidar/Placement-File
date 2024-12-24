// We have the data in form of sorted array. our task is to make a BST

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node *arrayTobst(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node *root=new node(arr[mid]);
    root->left=arrayTobst(arr,start,mid-1);
    root->right=arrayTobst(arr,mid+1,end);
    return root;
}
void traverse(node *root){
    if(root==NULL){
        return;
    }
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    node *root=arrayTobst(arr,0,n-1);
    traverse(root);
    return 0;
}