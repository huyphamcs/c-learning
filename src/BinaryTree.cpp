#include <iostream>
using namespace std;

// Node implementations
template<class T>
Node<T>::Node() {
    left = nullptr;
    right = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    left = nullptr;
    right = nullptr;
    this->data = data;
}

// BinaryTree implementations
template<class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree(Node<T>* root) {
    this->root = root;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    // Note: This destructor doesn't delete nodes to avoid double deletion
    // In a real implementation, you'd need proper memory management
}

template<class T>
void BinaryTree<T>::preOrder() {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    if (root->left != nullptr) {
        BinaryTree<T>* left = new BinaryTree<T>();
        left->root = root->left;
        left->preOrder();
        delete left;
    }
    if (root->right != nullptr) {
        BinaryTree<T>* right = new BinaryTree<T>();
        right->root = root->right;
        right->preOrder();
        delete right;
    }
}

template<class T>
void BinaryTree<T>::inOrder() {
    if (root == nullptr) return;
    
    if (root->left != nullptr) {
        BinaryTree<T>* left = new BinaryTree<T>();
        left->root = root->left;
        left->inOrder();
        delete left;
    }
    cout << root->data << " ";
    if (root->right != nullptr) {
        BinaryTree<T>* right = new BinaryTree<T>();
        right->root = root->right;
        right->inOrder();
        delete right;
    }
}

template<class T>
void BinaryTree<T>::postOrder() {
    if (root == nullptr) return;
    
    if (root->left != nullptr) {
        BinaryTree<T>* left = new BinaryTree<T>();
        left->root = root->left;
        left->postOrder();
        delete left;
    }
    if (root->right != nullptr) {
        BinaryTree<T>* right = new BinaryTree<T>();
        right->root = root->right;
        right->postOrder();
        delete right;
    }
    cout << root->data << " ";
}

template<class T>
void BinaryTree<T>::infix() {
    if (root == nullptr) return;
    
    if ((root->data == '+') || root->data == '-' || root->data == '*' || root->data == '/') {
        cout << root->data << " ";
    } else {
        cout << "(";
        if (root->left != nullptr) {
            BinaryTree<T>* left = new BinaryTree<T>();
            left->root = root->left;
            left->infix();
            delete left;
        }
        cout << root->data;
        if (root->right != nullptr) {
            BinaryTree<T>* right = new BinaryTree<T>();
            right->root = root->right;
            right->infix();
            delete right;
        }
        cout << ")";
    }
}

template<class T>
void BinaryTree<T>::printTree(string prefix, bool isLast) {
    if (root == nullptr) return;
    
    cout << prefix;
    cout << (isLast ? "└── " : "├── ");
    cout << root->data << endl;
    
    if (root->left != nullptr || root->right != nullptr) {
        if (root->left != nullptr) {
            BinaryTree<T>* left = new BinaryTree<T>(root->left);
            left->printTree(prefix + (isLast ? "    " : "│   "), root->right == nullptr);
            delete left;
        }
        if (root->right != nullptr) {
            BinaryTree<T>* right = new BinaryTree<T>(root->right);
            right->printTree(prefix + (isLast ? "    " : "│   "), true);
            delete right;
        }
    }
}
