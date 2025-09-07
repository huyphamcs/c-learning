#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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
class BinaryTree {
public:
    Node<T>* root;
    
    BinaryTree();
    BinaryTree(Node<T>* root);
    virtual ~BinaryTree();
    
    void preOrder();
    void inOrder();
    void postOrder();
    void infix();
    void printTree(std::string prefix = "", bool isLast = true);
};

// Include implementation for templates
#include "../src/BinaryTree.cpp"

#endif
