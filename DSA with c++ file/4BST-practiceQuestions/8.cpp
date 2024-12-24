// BST to greater sum tree:-  A tree is given we want to find the maximum element of tree then add 1st max to 2nd max 
// now 2nd max is sum of 1st+2nd then add this to 3rd max till root
//       5                   30 
//      / \                 /  \
//     3   8      =>      33    18
//        / \                  /  \
//       7   10              25    10

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
int sum=0;
void gst(node *root){
    if(root==NULL){
        return;
    }
    gst(root->right);
    root->data+=sum;
    sum=root->data;
    gst(root->left);
}
void traverse(node *root){
    if(root==NULL){
        return;
    }
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}
int main(){
    root=insertBST(root,5);
    root=insertBST(root,7);
    root=insertBST(root,4);
    root=insertBST(root,3);
    root=insertBST(root,2);
    root=insertBST(root,6);
    root=insertBST(root,1);
    cout<<"Before GST: ";
    traverse(root);
    cout<<endl;
    cout<<"After GST: ";
    gst(root);
    traverse(root);
    return 0;
}