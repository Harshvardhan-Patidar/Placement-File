// Our task is to merge two BST and return only its data in sorted form 

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
void inorder(node *root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> merge(node *root,node *root2){
    vector<int> ans;
    if(root==NULL && root2==NULL){
        return ans;
    }
    if(root->data<root2->data){
        inorder(root,ans);
        inorder(root2,ans);
        return ans;
    }
    else if(root->data>root2->data){
        inorder(root2,ans);
        inorder(root,ans);
        return ans;
    }
    return ans;
}
int main(){
    node *root=NULL;
    node *root2=NULL;
    root=insertBST(root,1);
    root=insertBST(root,2);
    root=insertBST(root,3);
    root=insertBST(root,4);
    root=insertBST(root,5);
    root2=insertBST(root2,6);
    root2=insertBST(root2,7);
    root2=insertBST(root2,8);
    vector<int> result=merge(root,root2);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}