// Chech the max width in tree:- no of node present in any level

#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
};
node *root=NULL;
node *newNode(int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void maxWidth(node *p){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    int size=0,width=1;
    while(q.empty()==false){
        size=q.size();
        width=max(width,size);
        for(int i=0;i<size;i++){
            p=q.front();
            q.pop();
            if(p->left!=NULL){
                q.push(p->left);
            }
            if(p->right!=NULL){
                q.push(p->right);
            }
        }
    }
    cout<<"Max width: "<<width;
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(1);
    maxWidth(root);
    return 0;
}