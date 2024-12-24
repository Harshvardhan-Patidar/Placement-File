// Target is given, our task is to find that any pair is exist or not which is equal to target

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
node *root=NULL;
node *insertBST(node *root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<root->data){
        root->left=insertBST(root->left,data);
    }
    if(data>root->data){
        root->right=insertBST(root->right,data);
    }
    return root;
}
bool search(node *root,int value){
    if(root==NULL){
        return false;
    }
    if(root->data==value){
        return true;
    }
    else if(root->data>value){
        return search(root->left,value);
    }
    else{
        return search(root->right,value);
    }
}
bool targetSum(node *root,int k){
    if(root==NULL){
        return false;
    }
    int comp=k-root->data;
    if(search(root,comp) && root->data!=comp){
        return true;
    }
    return targetSum(root->left,k) || targetSum(root->right,k);
}
bool targetSum2(node *root,int k,unordered_set<int>& set){
    if(root==NULL){
        return false;
    }
    int comp=k-root->data;
    if(set.count(comp)){
        return true;
    }
    set.insert(root->data);
    return targetSum2(root->left,k,set) || targetSum2(root->right,k,set);
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    // if(targetSum(root,8)){
    //     cout<<"Pair is present";
    // }
    // else{
    //     cout<<"Pair is not present";
    // }
    unordered_set<int> set;
    if(targetSum2(root,8,set)){
        cout<<"Pair is present";
    }
    else{
        cout<<"Pair is not present";
    }
    return 0;
}