// Task is to count the total node of node between intervel

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
int i=0;
void count(node *root,int l,int r){
    if(root==NULL){
        return;
    }
    if(root->data>=l && root->data<=r){
        i++;
    }
    count(root->left,l,r);
    count(root->right,l,r);
}
int count2(node *root,int l,int r){
    if(root==NULL){
        return 0;
    }
    if(root->data>=l && root->data<=r){
        return 1+count2(root->left,l,r)+count2(root->right,l,r);
    }
    else if(root->data<l){
        return count2(root->right,l,r);
    }
    else{
        return count2(root->left,l,r);
    }
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    count(root,2,5);
    cout<<"Total no of no between 2 to 5: "<<i;
    return 0;
}