#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

template<class T>
class Node {
public:
    Node<T>* left;
    T data;
    Node<T>* right;
    
    Node();
    Node(T data);
    virtual ~Node() = default;
};

template<class T>
class BinarySearchTree {
public:
    Node<T>* root;
    
    BinarySearchTree();
    BinarySearchTree(T data);
    virtual ~BinarySearchTree();
    
    // Traversal methods
    void preOrder();
    void inOrder();
    void postOrder();
    
    // BST operations
    void insert(T data);
    void deleteNode(T data);
    bool existNode(T data);
    
    // Search operations
    Node<T>* findNode(T data);
    Node<T>* findPreviousNode(T data);
    Node<T>* findSmallest();
    Node<T>* findLargest();
    
    // Utility methods
    void visualize(Node<T>* node = nullptr, std::string prefix = "", bool isLeft = true, bool isRoot = true);
};

// Include implementation for templates
#include "../src/BinarySearchTree.cpp"

#endif
