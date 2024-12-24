#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int nodes(Node *root){
    if(root==NULL) return 0;
    return nodes(root->left)+nodes(root->right)+1;
}
bool isMaxHeap(Node* root,int Tnode,int index){ 
    if (root == nullptr) {
        return true;
    }
    if(index>=Tnode){
        return true;
    }
    if (root->left != nullptr && root->data < root->left->data) {
        return false;
    }
    if (root->right != nullptr && root->data < root->right->data) {
        return false;
    }
    return isMaxHeap(root->left,Tnode,2*index+1) && isMaxHeap(root->right,Tnode,2*index+2);
}
int main() {
    Node* root = new Node(10);
    root->left =new Node(8);
    root->right =new Node(9);
    root->left->left =new Node(7);
    root->left->right =new Node(6);
    root->right->left =new Node(5);
    root->right->right =new Node(4);
    int Tnode=nodes(root);
    if (isMaxHeap(root,Tnode,0)) {
        cout << "The binary tree is a max heap." << endl;
    } else {
        cout << "The binary tree is not a max heap." << endl;
    }

    return 0;
}