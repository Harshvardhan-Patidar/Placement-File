// Two values is give, our task is to find the lowest common ancestor to two given node

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
    if(data>root->data){
        root->right=insertBST(root->right,data);
    }
    return root;
}
int LCA(node *root,int p,int q){
    if(root==NULL){
        return 0;
    }
    if(root->data>p && root->data<q){
        return root->data;
    }
    else if(root->data<p && root->data<q){
        return LCA(root->right,p,q);
    }
    else if(root->data>p && root->data>q){
        return LCA(root->left,p,q);
    }
    return root->data;
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    cout<<"Lowest comman ancestor: "<<LCA(root,2,5);
    return 0;
}