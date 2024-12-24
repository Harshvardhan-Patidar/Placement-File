// Task to implement the level order traversal(print root then left to right)

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
void levelorder(node *current){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        current=q.front();
        cout<<current->data<<" ";
        q.pop();
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
}
int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(7);
    levelorder(root);
    return 0;
}