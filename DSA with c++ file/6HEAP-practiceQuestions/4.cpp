// Task is to convert BST to max heap

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left=right=nullptr;
    }
};
void bstToMaxHeap(Node* root, priority_queue<int>& maxHeap) {
    if (root == nullptr) return;
    bstToMaxHeap(root->left, maxHeap);
    maxHeap.push(root->data);
    bstToMaxHeap(root->right, maxHeap);
}

int main() {
    Node* root = new Node{4};
    root->left = new Node{2};
    root->right = new Node{6};
    root->left->left = new Node{1};
    root->left->right = new Node{3};
    root->right->left = new Node{5};
    root->right->right = new Node{7};
    priority_queue<int> maxHeap;
    bstToMaxHeap(root, maxHeap);
    cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    return 0;
}