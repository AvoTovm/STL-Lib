#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
struct Node {
    T key;
    Node* left;
    Node* right;
    int height;

    Node(T value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>   
class AVLTree {
    public:
        AVLTree() : root(nullptr) {}

        void insert(T key){
            root = insert(root, key);
        }

        void deleteKey(T key){
            root = deleteNode(root, key);
        }

        bool search(T key){
            return search(root, key);
        }

        void inOrder(){
            inOrder(root);
            std::cout<< "\n";
        }

    private:
        Node<T>* root;

        int getHeight(Node<T>* node);
        int getBalanceFactor(Node<T>* node);

        Node<T>* rightRotate(Node<T>* y);
        Node<T>* leftRotate(Node<T>* x);
        Node<T>* insert(Node<T>* node, T key);
        Node<T>* minValueNode(Node<T>* node);
        Node<T>* deleteNode(Node<T>* root, T key);

        bool search(Node<T>* root, T key);
        void inOrder(Node<T>* root);
};

template <typename T>
int AVLTree<T>::getHeight(Node<T> *node){
    return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::getBalanceFactor(Node<T> *node){
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <typename T>
Node<T> *AVLTree<T>::rightRotate(Node<T> *y){
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right) + 1);
    x->height = std::max(getHeight(x->left), getHeight(x->right) + 1);

    return x;
}

template <typename T>
Node<T> *AVLTree<T>::leftRotate(Node<T> *x){
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right) + 1);
    x->height = std::max(getHeight(x->left), getHeight(x->right) + 1);

    return y;
}

template <typename T>
Node<T> *AVLTree<T>::insert(Node<T> *node, T key){
    if(!node) return new Node<T>(key);

        if(key < node->key)
            node->left = insert(node->left, key);
        else if(key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        if(balance > 1 && key < node->left->key) return rightRotate(node);
        if(balance < -1 && key > node->right->key) return leftRotate(node);
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
}

template <typename T>
Node<T> *AVLTree<T>::minValueNode(Node<T> *node){
    Node<T>* current = node;
    while(current->left) current = current->left;
    return current; 
}

template <typename T>
Node<T> *AVLTree<T>::deleteNode(Node<T> *root, T key){
    if(!root) return root;

        if(key < root->key)
            root->left = deleteNode(root->left, key);
        else if(key > root->key)
            root->right = deleteNode(root->right, key);
        else{
            if(!root->left || !root->right){
                Node<T>* temp = root->left ? root->left : root->right;
                if(!temp){
                    temp = root;
                    root = nullptr;
                }else{
                    *root = *temp;
                }
                delete temp;
            }else{
                Node<T>* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if(!root) return root;

        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        int balance = getBalanceFactor(root);

        if(balance > 1 && getBalanceFactor(root->left) >= 0) return rightRotate(root);
        if(balance > 1 && getBalanceFactor(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if(balance < -1 && getBalanceFactor(root->right) <= 0) return leftRotate(root);
        if(balance < -1 && getBalanceFactor(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
}

template <typename T>
bool AVLTree<T>::search(Node<T> *root, T key){
    if(!root) return false;
    if(root->key == key) return true;
    if(key < root->key) return search(root->left, key);
    return search(root->right, key);
}

template <typename T>
void AVLTree<T>::inOrder(Node<T> *root){
    if(root){
        inOrder(root->left);
        std::cout<<root->key<<" ";
        inOrder(root->right);
    }
}
