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
int Max(node *root){
    if(root->right){
        return Max(root->right);
    }
    else{
        return root->data;
    }
}
node *deleteNode(node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        // condition for two child
        if(root->left && root->right){
            int Lmax=Max(root->left);
            root->data=Lmax;
            root->left=deleteNode(root->left,Lmax);
        }
        // One right child
        else if(root->right){
            return root->right;
        }
        // One left child
        else if(root->left){
            return root->left;
        }
        // No child
        else{
            return NULL;
        }
    }
    return root;
}
void traversal(node *root){
    if(root==NULL){
        return;
    }
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    cout<<"Before deletion: ";
    traversal(root);
    cout<<endl;
    cout<<"After deletion: ";
    deleteNode(root,3);
    traversal(root);
    return 0;
}