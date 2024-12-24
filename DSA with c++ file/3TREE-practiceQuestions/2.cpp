// Do a spiral traversal mean in the form of spring(print root then right left then left right)

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
void spiralTraversal(){
    if(root==NULL){
        return;
    }
    int level=1;
    queue<node*> q;
    vector<int> ans;
    q.push(root);
    while(q.empty()==false){
        vector<int> v;
        int size=q.size();
        for(int i=0;i<size;i++){
            node *current=q.front();
            v.push_back(current->data);
            q.pop();
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
        }
        if(level%2==0){
            reverse(v.begin(),v.end());
        }
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        level++;
    }
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i] << " ";
    }
}
int main(){
    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(2);
    spiralTraversal();
    return 0;
}