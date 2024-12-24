// We want to find the Kth smallest element in BST

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
int inorderSmallest(node *root,int &k){
    if(root==NULL){
        return -1;
    }
    int left=inorderSmallest(root->left,k);
    if(left!=-1){
        return left;
    }
    k=k-1;
    if(k==0){
        return root->data;
    }
    return inorderSmallest(root->right,k);
}
int smallestElement(node *root,int k){
    return inorderSmallest(root,k);
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
    cout<<"Kth Smallest value: "<<smallestElement(root,1);
    return 0;
}