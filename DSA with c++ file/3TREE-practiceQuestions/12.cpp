// Task is to print the vertically node

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *createNode(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void verticalTraversal(node *root,int hd,map<int,vector<int>>& mp){
    if(root==NULL){
        return;
    }
    mp[hd].push_back(root->data);
    verticalTraversal(root->left,hd-1,mp);
    verticalTraversal(root->right,hd+1,mp);
}
int main(){
    node *root=createNode(1);
    root->left=createNode(2);
    root->left->left=createNode(3);
    root->left->right=createNode(4);
    root->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    map<int,vector<int>> mp;
    verticalTraversal(root,0,mp);   // here 0 is the horizontal distance starting from root=0
    for(auto i:mp){
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}