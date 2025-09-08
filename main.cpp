// #include <iostream>
// using namespace std;

// template <class T>
// class Node
// {
// public:
//     Node<T> *left;
//     T data;
//     Node<T> *right;

//     Node()
//     {
//         left = nullptr;
//         right = nullptr;
//     }
//     Node(T data)
//     {
//         this->data = data;
//         left = nullptr;
//         right = nullptr;
//     }
//     virtual ~Node() = default;
// };

// template <class T>
// class binarySearchTree
// {
// public:
//     Node<T> *root;
//     binarySearchTree()
//     {
//         this->root = nullptr;
//     }

//     binarySearchTree(T data)
//     {
//         Node<T> *newNode = new Node<T>(data);
//         root = newNode;
//     }
//     void preOrder()
//     {
//         if (root == nullptr)
//             return;
//         cout << root->data << " ";
//         if (root->left != nullptr)
//         {
//             binarySearchTree<T> *left = new binarySearchTree<T>();
//             left->root = root->left;
//             left->preOrder();
//             delete left;
//         }
//         if (root->right != nullptr)
//         {
//             binarySearchTree<T> *right = new binarySearchTree<T>();
//             right->root = root->right;
//             right->preOrder();
//             delete right;
//         }
//     }

//     void inOrder()
//     {
//         if (root == nullptr)
//             return;
//         if (root->left != nullptr)
//         {
//             binarySearchTree<T> *left = new binarySearchTree<T>();
//             left->root = root->left;
//             left->inOrder();
//             delete left;
//         }
//         cout << root->data << " ";
//         if (root->right != nullptr)
//         {
//             binarySearchTree<T> *right = new binarySearchTree<T>();
//             right->root = root->right;
//             right->inOrder();
//             delete right;
//         }
//     }
//     void postOrder()
//     {
//         if (root == nullptr)
//             return;

//         if (root->left != nullptr)
//         {
//             binarySearchTree<T> *left = new binarySearchTree<T>();
//             left->root = root->left;
//             left->postOrder();
//             delete left;
//         }
//         if (root->right != nullptr)
//         {
//             binarySearchTree<T> *right = new binarySearchTree<T>();
//             right->root = root->right;
//             right->postOrder();
//             delete right;
//         }
//         cout << root->data << " ";
//     }
//     void insert(T data)
//     {
//         Node<T> *newNode = new Node<T>(data);
//         if (root == nullptr)
//         {
//             root = newNode;
//             return;
//         }
//         Node<T> *tempPtr = root;
//         while (true)
//         {
//             if (data < tempPtr->data)
//             {
//                 if (tempPtr->left == nullptr)
//                 {
//                     tempPtr->left = newNode;
//                     break;
//                 }
//                 else
//                     tempPtr = tempPtr->left;
//             }
//             else
//             {
//                 if (tempPtr->right == nullptr)
//                 {
//                     tempPtr->right = newNode;
//                     break;
//                 }
//                 else
//                     tempPtr = tempPtr->right;
//             }
//         }
//     }
//     void visualize(Node<T> *node = nullptr, string prefix = "", bool isLeft = true, bool isRoot = true)
//     {
//         if (isRoot)
//         {
//             node = root;
//             if (node == nullptr)
//             {
//                 cout << "Empty tree" << endl;
//                 return;
//             }
//             cout << "Root: " << node->data << endl;
//             if (node->left != nullptr || node->right != nullptr)
//             {
//                 if (node->left != nullptr)
//                 {
//                     visualize(node->left, "├── ", true, false);
//                 }
//                 if (node->right != nullptr)
//                 {
//                     visualize(node->right, "└── ", false, false);
//                 }
//             }
//             return;
//         }

//         if (node == nullptr)
//         {
//             return;
//         }

//         cout << prefix;
//         if (isLeft)
//         {
//             cout << "L: " << node->data << " (< " << node->data << ")" << endl;
//         }
//         else
//         {
//             cout << "R: " << node->data << " (>= " << node->data << ")" << endl;
//         }

//         if (node->left != nullptr || node->right != nullptr)
//         {
//             string newPrefix = prefix;
//             if (prefix == "├── ")
//                 newPrefix = "│   ";
//             else if (prefix == "└── ")
//                 newPrefix = "    ";

//             if (node->left != nullptr)
//             {
//                 visualize(node->left, newPrefix + "├── ", true, false);
//             }
//             if (node->right != nullptr)
//             {
//                 visualize(node->right, newPrefix + "└── ", false, false);
//             }
//         }
//     }
//     bool existNode(T data)
//     {
//         Node<T> *tempPtr = root;
//         if (tempPtr->data == data)
//             return true;
//         while (true)
//         {
//             if (data < tempPtr->data)
//                 tempPtr = tempPtr->left;
//             else
//                 tempPtr = tempPtr->right;
//             if (tempPtr == nullptr)
//             {
//                 return false;
//             }
//             else if (tempPtr->data == data)
//             {
//                 return true;
//             }
//         }
//     }
//     Node<T> *findNode(T data)
//     {
//         Node<T> *tempPtr = root;
//         if (tempPtr->data == data)
//             return tempPtr;
//         while (true)
//         {
//             if (data < tempPtr->data)
//                 tempPtr = tempPtr->left;
//             else
//                 tempPtr = tempPtr->right;
//             if (tempPtr == nullptr)
//             {
//                 return nullptr;
//             }
//             else if (tempPtr->data == data)
//             {
//                 return tempPtr;
//             }
//         }
//     }
//     void deleteNode(T data) {
//         Node<T>* newNode = findNode(data);
//         if (newNode->left == nullptr && newNode->right == nullptr) {
//             delete newNode;
//             return;
//         }
//         if (newNode->right == nullptr && newNode->left != nullptr){
            
//         }
//     }


// };

// int main()
// {
//     binarySearchTree<int> *newTree = new binarySearchTree<int>();
//     newTree->insert(15);
//     newTree->insert(6);
//     newTree->insert(23);
//     newTree->insert(4);
//     newTree->insert(5);
//     newTree->insert(71);
//     newTree->insert(7);
//     newTree->insert(50);
//     // newTree->inOrder();
//     newTree->visualize();
//     // newTree->preOrder();
//     // cout << newTree->existNode(10);
//     Node<int>* newNode = newTree->findNode(50);
//     cout << newNode << endl;
//     // cout << newNode->right->data << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int longestSubArray(int *arr, int size)
{
    int left = 0;
    int right = 0;
    int storedResult = 0;
    int currentResult = 0;

    while(right <= size){
        if(arr[left] == arr[right]){
            right++;
            currentResult++;
            continue;
        }
        if (currentResult>storedResult){
            storedResult = currentResult;
            currentResult = 0;
        }
        left = right;

    }
    return storedResult;
}

int main()
{
    int arr[] = {7, 3, 3, 3,3,3,3, 2, 2, 2, 2,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << longestSubArray(arr,size) << endl;
    return 0;
}