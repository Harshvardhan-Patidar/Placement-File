// Task is to find min time to burn tree from leaf
// condition:    that last node is burn in 0time and it adjecent node is burn in +1time

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root=NULL;
node *createNode(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int result=0;
int minTime(node *root,int target,int dis){
    if(root==NULL){
        return 0;
    }
    if(root->data=target){
        dis=0;   // it show that target node is here
        return 1; // for counting a height
    }
    int Ldis=-1,Rdis=-1;   //if target not find
    int Lh=minTime(root->left,target,Ldis);
    int Rh=minTime(root->right,target,Rdis);
    if(Ldis!=-1){
        dis=Ldis+1;
        result=max(result,dis+Rh);   //here result will contain distance from root to target and height of another side
    }
    if(Rdis!=-1){
        dis=Rdis+1;
        result=max(result,dis+Lh);
    }
    cout<<result;
    return max(Lh,Rh)+1;   // to calculate the height of tree
}
int main(){
    root=createNode(3);
    root->left=createNode(2);
    root->right=createNode(7);
    root->left->left=createNode(1);
    root->left->right=createNode(4);
    root->right->left=createNode(5);
    root->right->right=createNode(8);
    root->right->left->left=createNode(9);
    root->right->left->right=createNode(6);
    int target=9;
    int dis=-1;
    minTime(root,target,dis);
    cout<<"Minimum time taken to burn tree is: "<<result;
    return 0;
}