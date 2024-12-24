// Task is to print the bottom view of the tree: solve using the concept of horizontal distance

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
void bottomViewRecursive(node *root,int hd,map<int,vector<int>> &mp){
    if(root==NULL){
        return;
    }
    mp[hd].push_back(root->data);
    bottomViewRecursive(root->left,hd-1,mp);
    bottomViewRecursive(root->right,hd+1,mp);
}
void bottomViewIterative(node *current,int hd,map<int,node*> &mp){
    if(current==NULL){
        return;
    }
    queue<pair<node*,int>> q;
    q.push({current,0});
    while(q.empty()==false){
        current=q.front().first;
        hd=q.front().second;
        q.pop();
        mp[hd]=current;
        if(current->left!=NULL){
            q.push({current->left,hd-1});
        }
        if(current->right!=NULL){
            q.push({current->right,hd+1});
        }
    }
}
int main(){
    node *root=createNode(3);
    root->left=createNode(4);
    root->left->left=createNode(12);
    root->left->right=createNode(9);
    root->left->right->left=createNode(6);
    root->left->right->right=createNode(7);
    root->right=createNode(8);
    root->right->left=createNode(2);
    root->right->right=createNode(5);
    root->right->right->left=createNode(1);
    map<int,vector<int>> mp;
    bottomViewRecursive(root,0,mp);
    for(auto i:mp){
        cout<<i.second.back()<<" ";
    }
    cout<<endl;
    map<int,node *> mp;
    bottomViewIterative(root,0,mp);
    for(auto i:mp){
        cout<<i.second->data<<" ";
    }
    return 0;
}