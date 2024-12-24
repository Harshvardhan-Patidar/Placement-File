// Our task is to find the size of largest binary search tree present in binary tree

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
vector<int> helper(node *root){
    if(root==NULL){
        return {1,0,INT_MAX,INT_MIN};       //{check isBST,size of bst,min data,max data}
    }
    if(root->left!=NULL && root->right!=NULL){
        return {1,1,root->data,root->data};
    }
    vector<int> ln=helper(root->left);
    vector<int> rn=helper(root->right);
    if(ln[0] && rn[0]){
        if(root->data>ln[3] && root->data<rn[2]){
            int x=ln[2];
            int y=rn[3];
            if(x==INT_MAX){
                x=root->data;
            }
            if(y==INT_MIN){
                y=root->data;
            }
            return {1,ln[1]+rn[1]+1,x,y};
        }
    }
    return {0,max(ln[1],rn[1]),INT_MIN,INT_MAX};
}
int largestBST(node *root){
    vector<int>ans=helper(root);
    return ans[1];
}
int main(){
    root=insertBST(root,1);
    root=insertBST(root,2);
    root=insertBST(root,3);
    root=insertBST(root,4);
    root=insertBST(root,5);
    int size=largestBST(root);
    cout<<"Largest BST size: "<<size<<endl;
    return 0;
}