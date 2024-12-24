// Our task is to find the median of BST

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
node *insertBST(node *root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<root->data){
        root->left=insertBST(root->left,data);
    }
    else if(data>root->data){
        root->right=insertBST(root->right,data);
    }
    return root;
}
void countNode(node *root,int &n){
    if(root==NULL){
        return;
    }
    countNode(root->left,n);
    n++;
    countNode(root->right,n);
}
void finder(node *root,node *&cur,node *&pre,int &c,int x,int &f){
    if(root==NULL){
        return;
    }
    finder(root->left,cur,pre,c,x,f);
    if(pre==NULL){
        pre=root;
        c++;
    }
    else if(c==k){
        cur==root;
        f=1;
        return;
    }
    else if(f==0){
        pre=root;
        c++;
    }
    finder(root->right,cur,pre,c,x,f);
}
float findMedian(node *root){
    int n=0;
    countNode(root,n);
    node *cur=NULL;
    node *pre=NULL;
    int c=1;
    int x=(n/2)+1;
    int f=0;
    finder(root,cur,pre,c,x,f);
    if(n%2==1){
        float ans=cur->data*1.0;
        return ans;
    }
    else{
        float ans=((cur->data+pre->data)*1.0)/2*1.0;
        return ans;
    }
}
int main(){
    root=insertBST(root,1);
    root=insertBST(root,2);
    root=insertBST(root,3);
    root=insertBST(root,4);
    root=insertBST(root,5);
    return 0;
}