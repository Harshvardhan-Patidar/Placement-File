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
bool searchData(node *root,int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(val<root->data){
        return searchData(root->left,val);
    }
    else if(val>root->data){
        return searchData(root->right,val);
    }
    return false;
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    if(searchData(root,2)){
        cout<<"Present";
    }
    else{
        cout<<"Not present";
    }
    return 0;
}