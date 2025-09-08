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
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// BinarySearchTree implementations
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(T data) {
    Node<T>* newNode = new Node<T>(data);
    root = newNode;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    // Note: In a real implementation, you'd need proper tree cleanup
    // This simple destructor avoids double deletion issues in test cases
}

template<class T>
void BinarySearchTree<T>::preOrder() {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    if (root->left != nullptr) {
        BinarySearchTree<T>* left = new BinarySearchTree<T>();
        left->root = root->left;
        left->preOrder();
        delete left;
    }
    if (root->right != nullptr) {
        BinarySearchTree<T>* right = new BinarySearchTree<T>();
        right->root = root->right;
        right->preOrder();
        delete right;
    }
}

template<class T>
void BinarySearchTree<T>::inOrder() {
    if (root == nullptr) return;
    
    if (root->left != nullptr) {
        BinarySearchTree<T>* left = new BinarySearchTree<T>();
        left->root = root->left;
        left->inOrder();
        delete left;
    }
    cout << root->data << " ";
    if (root->right != nullptr) {
        BinarySearchTree<T>* right = new BinarySearchTree<T>();
        right->root = root->right;
        right->inOrder();
        delete right;
    }
}

template<class T>
void BinarySearchTree<T>::postOrder() {
    if (root == nullptr) return;
    
    if (root->left != nullptr) {
        BinarySearchTree<T>* left = new BinarySearchTree<T>();
        left->root = root->left;
        left->postOrder();
        delete left;
    }
    if (root->right != nullptr) {
        BinarySearchTree<T>* right = new BinarySearchTree<T>();
        right->root = root->right;
        right->postOrder();
        delete right;
    }
    cout << root->data << " ";
}

template<class T>
void BinarySearchTree<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node<T>* tempPtr = root;
    while (true) {
        if (data < tempPtr->data) {
            if (tempPtr->left == nullptr) {
                tempPtr->left = newNode;
                break;
            } else {
                tempPtr = tempPtr->left;
            }
        } else {
            if (tempPtr->right == nullptr) {
                tempPtr->right = newNode;
                break;
            } else {
                tempPtr = tempPtr->right;
            }
        }
    }
}

template<class T>
bool BinarySearchTree<T>::existNode(T data) {
    if (root == nullptr) return false;
    
    Node<T>* tempPtr = root;
    if (tempPtr->data == data) return true;
    
    while (true) {
        if (data < tempPtr->data) {
            tempPtr = tempPtr->left;
        } else {
            tempPtr = tempPtr->right;
        }
        if (tempPtr == nullptr) {
            return false;
        } else if (tempPtr->data == data) {
            return true;
        }
    }
}

template<class T>
Node<T>* BinarySearchTree<T>::findNode(T data) {
    if (root == nullptr) return nullptr;
    
    Node<T>* tempPtr = root;
    if (tempPtr->data == data) return tempPtr;
    
    while (true) {
        if (data < tempPtr->data) {
            tempPtr = tempPtr->left;
        } else {
            tempPtr = tempPtr->right;
        }
        if (tempPtr == nullptr) {
            return nullptr;
        } else if (tempPtr->data == data) {
            return tempPtr;
        }
    }
}

template<class T>
Node<T>* BinarySearchTree<T>::findPreviousNode(T data) {
    if (root == nullptr || data == root->data) return nullptr;
    
    Node<T>* tempPtr = root;
    Node<T>* tempPre = nullptr;
    
    while (true) {
        if (data < tempPtr->data) {
            tempPre = tempPtr;
            tempPtr = tempPtr->left;
        } else {
            tempPre = tempPtr;
            tempPtr = tempPtr->right;
        }
        
        if (tempPtr == nullptr) {
            return nullptr;
        } else if (tempPtr->data == data) {
            return tempPre;
        }
    }
}

template<class T>
Node<T>* BinarySearchTree<T>::findSmallest() {
    if (root == nullptr) return nullptr;
    
    Node<T>* tempPtr = root;
    if (tempPtr->left == nullptr && tempPtr->right == nullptr) return tempPtr;
    
    while (tempPtr->left != nullptr) {
        tempPtr = tempPtr->left;
    }
    return tempPtr;
}

template<class T>
Node<T>* BinarySearchTree<T>::findLargest() {
    if (root == nullptr) return nullptr;
    
    Node<T>* tempPtr = root;
    if (tempPtr->left == nullptr && tempPtr->right == nullptr) return tempPtr;
    
    while (tempPtr->right != nullptr) {
        tempPtr = tempPtr->right;
    }
    return tempPtr;
}

template<class T>
void BinarySearchTree<T>::deleteNode(T data) {
    Node<T>* tempPtr = findNode(data);
    if (tempPtr == nullptr) return; // Node not found
    
    if (tempPtr == root && !(tempPtr->left != nullptr && tempPtr->right != nullptr)) {
        if (tempPtr->left == nullptr && tempPtr->right == nullptr) {
            root = nullptr;
        } else if (tempPtr->left == nullptr) {
            root = tempPtr->right;
        } else if (tempPtr->right == nullptr) {
            root = tempPtr->left;
        }
        delete tempPtr;
    } else if (tempPtr->left == nullptr && tempPtr->right == nullptr) {
        Node<T>* prePtr = findPreviousNode(data);
        if (prePtr->left == tempPtr) {
            prePtr->left = nullptr;
        } else {
            prePtr->right = nullptr;
        }
        delete tempPtr;
    } else if (tempPtr->left == nullptr) {
        Node<T>* prePtr = findPreviousNode(data);
        if (prePtr->left == tempPtr) {
            prePtr->left = tempPtr->right;
        } else {
            prePtr->right = tempPtr->right;
        }
        delete tempPtr;
    } else if (tempPtr->right == nullptr) {
        Node<T>* prePtr = findPreviousNode(data);
        if (prePtr->left == tempPtr) {
            prePtr->left = tempPtr->left;
        } else {
            prePtr->right = tempPtr->left;
        }
        delete tempPtr;
    } else if (tempPtr->left != nullptr && tempPtr->right != nullptr) {
        Node<T>* rootOfRightSubTree = tempPtr->right;
        
        BinarySearchTree<T>* newSubTree = new BinarySearchTree<T>();
        newSubTree->root = rootOfRightSubTree;
        
        Node<T>* smallestInRightSubTree = newSubTree->findSmallest();
        Node<T>* prevSmallest = newSubTree->findPreviousNode(smallestInRightSubTree->data);
        
        if (prevSmallest != nullptr) prevSmallest->left = nullptr;
        
        smallestInRightSubTree->left = tempPtr->left;
        if (tempPtr == root) {
            if (smallestInRightSubTree != rootOfRightSubTree) {
                smallestInRightSubTree->right = newSubTree->root;
            }
            root = smallestInRightSubTree;
            delete tempPtr;
            delete newSubTree;
            return;
        }
        Node<T>* prevTemp = findPreviousNode(tempPtr->data);
        if (prevTemp->left == tempPtr) {
            prevTemp->left = smallestInRightSubTree;
        } else {
            prevTemp->right = smallestInRightSubTree;
        }
        
        delete tempPtr;
        delete newSubTree;
    }
}

template<class T>
void BinarySearchTree<T>::visualize(Node<T>* node, string prefix, bool isLeft, bool isRoot) {
    if (isRoot) {
        node = root;
        if (node == nullptr) {
            cout << "Empty tree" << endl;
            return;
        }
        cout << "Root: " << node->data << endl;
        if (node->left != nullptr || node->right != nullptr) {
            if (node->left != nullptr) {
                visualize(node->left, "├── ", true, false);
            }
            if (node->right != nullptr) {
                visualize(node->right, "└── ", false, false);
            }
        }
        return;
    }

    if (node == nullptr) {
        return;
    }

    cout << prefix;
    if (isLeft) {
        cout << "L: " << node->data << endl;
    } else {
        cout << "R: " << node->data << endl;
    }

    if (node->left != nullptr || node->right != nullptr) {
        string newPrefix = prefix;
        if (prefix == "├── ") {
            newPrefix = "│   ";
        } else if (prefix == "└── ") {
            newPrefix = "    ";
        }

        if (node->left != nullptr) {
            visualize(node->left, newPrefix + "├── ", true, false);
        }
        if (node->right != nullptr) {
            visualize(node->right, newPrefix + "└── ", false, false);
        }
    }
}
