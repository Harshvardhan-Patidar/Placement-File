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
node *insertBST(node *root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<root->data){
        root->left=insertBST(root->left,data);
    }
    else if(data>root->data){
        root->right=insertBST(root->right,data);
    }
    return root;
}
int inorderLargest(node *root,int &k){
    if(root==NULL){
        return -1;
    }
    int right=inorderLargest(root->right,k);
    if(right!=-1){
        return right;
    }
    k=k-1;
    if(k==0){
        return root->data;
    }
    return inorderLargest(root->left,k);
}
int largestElement(node *root,int k){
    return inorderLargest(root,k);
}
int main(){
    root=insertBST(root,25);
    root=insertBST(root,20);
    root=insertBST(root,36);
    root=insertBST(root,10);
    root=insertBST(root,22);
    root=insertBST(root,30);
    root=insertBST(root,40);
    root=insertBST(root,5);
    root=insertBST(root,15);
    root=insertBST(root,28);
    root=insertBST(root,38);
    root=insertBST(root,48);
    cout<<"Kth Largest value: "<<largestElement(root,4);
    return 0;
}