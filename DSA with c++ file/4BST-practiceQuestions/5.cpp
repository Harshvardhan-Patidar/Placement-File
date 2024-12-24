// We have the key value, our task is to find the smallest and largest value near key in BST.
// largest is store in ceil & smallest is store in floor


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
void ceilAndfloor(node *root,int key){
    if(root==NULL){
        return;
    }
    int ceil,floor;
    while(root){
        if(root->data==key){
            ceil=root->data;
            floor=root->data;
            return;
        }
        else if(root->data>key){
            ceil=root->data;
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }
    cout<<"Ceil: "<<ceil<<endl<<"Floor: "<<floor;
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
    ceilAndfloor(root,41);
    return 0;
}