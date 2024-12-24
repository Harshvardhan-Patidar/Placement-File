//Our task is to find the predecessor and successor of the given key

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
void firstApproch(node *root,int key,node *&pre,node *&suc){
    if(root==NULL){
        return;
    }
    if(root->data<key){
        if(pre==NULL || root->data>pre->data){
            pre=root;
        }
        firstApproch(root->right,key,pre,suc);
    }
    else if(root->data>key){
        if(suc==NULL || root->data<suc->data){
            suc=root;
        }
        firstApproch(root->left,key,pre,suc);
    }
    cout<<pre->data<<" "<<suc->data;
}
node *findpre(node *root){
    node *p=root->left;
    while(p->right){
        p=p->right;
    }
    return p;
}
node *findsuc(node *root){
    node *p=root->right;
    while(p->left){
        p=p->left;
    }
    return p;
}
void secondApproch(node *root,node *&pre,node *&suc,int key){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left){
            pre=findpre(root);
        }
        if(root->right){
            suc=findsuc(root);
        }
        return;
    }
    if(root->data<key){
        pre=root;
        secondApproch(root->right,pre,suc,key);
    }
    if(root->data>key){
        suc=root;
        secondApproch(root->left,pre,suc,key);
    }
    cout<<"Predecessor: "<<pre->data<<endl<<"Successor: "<<suc->data;
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    node *pre=NULL;
    node *suc=NULL;
    firstApproch(root,4,pre,suc);
    return 0;
}