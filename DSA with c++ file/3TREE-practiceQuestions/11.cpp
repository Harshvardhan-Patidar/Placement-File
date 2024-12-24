// Our task is to print the right view of the tree(print extreme most right node)

#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
};
node *root=NULL;
node *createNode(int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void rightViewIterative(node *current){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=1;i<=count;i++){
        current=q.front();
        q.pop();
        if(i==count){
            cout<<current->data<<" ";
        }
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    }
}
int maxLevel=-1;
void rightViewRecursivr(node *root,int level){
    if(root==NULL){
        return;
    }
    if(maxLevel<level){
        cout<<root->data<<" ";
        maxLevel=level;
    }
    rightViewRecursivr(root->right,level+1);
    rightViewRecursivr(root->left,level+1);
}
int main(){
    root=createNode(10);
    root->left=createNode(8);
    root->right=createNode(2);
    root->left->left=createNode(3);
    root->left->right=createNode(5);
    root->right->left=createNode(1);
    rightViewIterative(root);
    cout<<endl;
    rightViewRecursivr(root,0);
    return 0;
}