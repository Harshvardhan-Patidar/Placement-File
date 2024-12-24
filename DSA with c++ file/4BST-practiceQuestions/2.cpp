// Check given tree is a BST or not

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
bool isBST(node* root,int min,int max) {
    if (root==NULL) {
        return true;
    }
    if (root->data<min || root->data>max) {
        return false;
    }
    return isBST(root->left,min,root->data-1) && isBST(root->right,root->data+1,max);
}
// Second approch
bool inorderForCheck(node *root,node *&pre){
    if(root==NULL){
        return true;
    }
    inorderForCheck(root->left,pre);
    if(pre!=NULL && root->data<=pre->data){
        return false;
    }
    pre=root;
    return inorderForCheck(root->right,pre);
}
bool isBST2(node *root){
    node *pre=NULL;
    return inorderForCheck(root,pre);
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    // if(isBST(root,INT_MIN,INT_MAX)){
    //     cout<<"It is BST";
    // }
    // else{
    //     cout<<"Not a BST";
    // }
    if(isBST2(root)){
        cout<<"It is BST";
    }
    else{
        cout<<"Not a BST";
    }
    return 0;
}