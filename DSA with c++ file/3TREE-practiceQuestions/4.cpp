// Print the diagonal of the tree

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
void diagonal(){
    if(root==NULL){
        return;
    }
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node *temp=q.front();
        q.pop();
        while(temp!=NULL){
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(1);
    diagonal();
    return 0;
}