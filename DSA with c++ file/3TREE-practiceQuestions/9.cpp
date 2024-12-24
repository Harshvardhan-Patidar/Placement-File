// Input the pair of data and chck that they are cousins or not:
//   condition: Bot at same level
//              both have different parent

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
int findHeight(node *root,int &parent,int value,int height){
    if(root==NULL){
        return 0;
    }
    if(root->data==value){
        return height;
    }
    parent=root->data;
    int left=findHeight(root->left,parent,value,height+1);
    if(left!=0){
        return left;
    }
    parent=root->data;
    int right=findHeight(root->right,parent,value,height+1);
    return right;
}
bool isCousins(node *root,int x,int y){
    if(root==NULL){
        return false;
    }
    int xparent=-1;
    int xheight=findHeight(root,xparent,x,0);
    int yparent=-1;
    int yheight=findHeight(root,yparent,y,0);
    if((xheight==yheight) && (xparent!=yparent)){
        return true;
    }
    return false;
}
int main(){
    root=createNode(10);
    root->left=createNode(8);
    root->right=createNode(2);
    root->left->left=createNode(3);
    root->left->right=createNode(5);
    root->right->left=createNode(1);
    if(isCousins(root,3,1)){
        cout<<"They our cousins";
    }
    else{
        cout<<"They our is not cousins";
    }
    return 0;
}