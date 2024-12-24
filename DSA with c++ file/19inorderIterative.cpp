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
void inorder(){
    if(root==NULL){
        return;
    }
    stack<node*> s;
    node *current=root;
    while(true){
        if(current!=NULL){
            s.push(current);
            current=current->left;
        }
        else{
            if(s.empty()){
                break;
            }
            else{
                current=s.top();
                s.pop();
                cout<<current->data<<" ";
                current=current->right;
            }
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
    inorder();
    return 0;
}