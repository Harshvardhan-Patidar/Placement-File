#include <iostream>
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
void preorder(node *p){
    if(p==NULL){
        return;
    }
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}
void inorder(node *p){
    if(p==NULL){
        return;
    }
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}
void postorder(node *p){
    if(p==NULL){
        return;
    }
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}
int main(){
    root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->right->left=createNode(7);
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
    return 0;
}