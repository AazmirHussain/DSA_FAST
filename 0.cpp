#include <iostream>
using namespace std;

class Node{
public:
    int data, height;
    Node* left;
    Node* right;
    
    Node(int val): data(val){
        left = right = nullptr;
        height = 1;
    }
};

class AVLConverter{
    int height(Node* N){
        if (N == nullptr){return 0;}
        return N->height;
    }
    
    int getBalance(Node* N){
        if (N == nullptr){return 0;}
        return (height(N->left) - height(N->right));
    }
    
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        
        return x;
    }
    
    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }
    
    Node* balanceNode(Node* node){
        if (node == nullptr){return node;}
        
        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);
        
        if (balance > 1 && getBalance(node->left) >= 0){ // LLC
            return rightRotate(node);}
        
        if (balance < -1 && getBalance(node->right) <= 0){ //RRC
            return leftRotate(node);}
        
        if (balance > 1 && getBalance(node->left) < 0){ //LRC
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && getBalance(node->right) > 0){ //RLC
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    void store(Node* node, Node* nodes[], int& index){
        if (node == nullptr){return;}
        store(node->left, nodes, index);
        nodes[index++] = node;
        store(node->right, nodes, index);
    }
    
    int countNodes(Node* root){
        if (root == nullptr){return 0;}
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    
    Node* buildBalancedTree(Node* nodes[], int start, int end){
        if (start > end){return nullptr;}
        
        int mid = (start + end) / 2;
        Node* root = nodes[mid];
        
        root->left = buildBalancedTree(nodes, start, mid - 1);
        root->right = buildBalancedTree(nodes, mid + 1, end);
        
        return balanceNode(root);
    }

public:
    Node* convertToAVL(Node* root){
        int n = countNodes(root);
        Node** nodes = new Node*[n];
        int index = 0;
        
        store(root, nodes, index);
        Node* newRoot = buildBalancedTree(nodes, 0, n - 1);
        
        delete[] nodes;
        return newRoot;
    }
};

Node* createBSTA(){
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(16);
    root->right->right = new Node(18);
    return root;
}

Node* createBSTB(){
    Node* root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(16);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    return root;
}