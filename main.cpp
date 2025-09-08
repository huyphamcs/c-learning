#include <iostream>
#include <string>
#include "include/BinarySearchTree.h"
using namespace std;

void testBST(const string& testName) {
    cout << "\n=== " << testName << " ===" << endl;
}

int main() {
    cout << "=== BINARY SEARCH TREE TEST CASES ===" << endl;
    
    // Test Case 1: Original Test Case
    testBST("Original BST Test Case");
    {
        BinarySearchTree<int>* newTree = new BinarySearchTree<int>();
        
        newTree->insert(15);
        newTree->insert(6);
        newTree->insert(23);
        newTree->insert(22);
        newTree->insert(4);
        newTree->insert(5);
        newTree->insert(71);
        newTree->insert(7);
        newTree->insert(50);
        
        cout << "Initial BST structure:" << endl;
        newTree->visualize();
        
        cout << "In-order traversal (should be sorted): ";
        newTree->inOrder();
        cout << endl;
        
        cout << "Deleting root node (15)..." << endl;
        newTree->deleteNode(15);
        
        cout << "BST after deletion:" << endl;
        newTree->visualize();
        
        cout << "In-order traversal after deletion: ";
        newTree->inOrder();
        cout << endl;
        
        delete newTree;
    }
    
    // Test Case 2: Basic BST Operations
    testBST("Basic BST Operations");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        
        // Insert values
        int values[] = {50, 30, 70, 20, 40, 60, 80};
        cout << "Inserting values: ";
        for (int val : values) {
            cout << val << " ";
            bst->insert(val);
        }
        cout << endl;
        
        cout << "BST structure:" << endl;
        bst->visualize();
        
        cout << "Pre-order: ";
        bst->preOrder();
        cout << endl;
        
        cout << "In-order: ";
        bst->inOrder();
        cout << endl;
        
        cout << "Post-order: ";
        bst->postOrder();
        cout << endl;
        
        cout << "Smallest element: " << bst->findSmallest()->data << endl;
        cout << "Largest element: " << bst->findLargest()->data << endl;
        
        delete bst;
    }
    
    // Test Case 3: Search Operations
    testBST("Search Operations");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        
        // Build a simple BST
        bst->insert(10);
        bst->insert(5);
        bst->insert(15);
        bst->insert(2);
        bst->insert(7);
        bst->insert(12);
        bst->insert(20);
        
        cout << "BST structure:" << endl;
        bst->visualize();
        
        // Test search operations
        int searchValues[] = {7, 15, 25, 2, 100};
        for (int val : searchValues) {
            cout << "Searching for " << val << ": ";
            if (bst->existNode(val)) {
                cout << "Found" << endl;
                Node<int>* prev = bst->findPreviousNode(val);
                if (prev != nullptr) {
                    cout << "  Previous node: " << prev->data << endl;
                } else {
                    cout << "  No previous node (root or not found)" << endl;
                }
            } else {
                cout << "Not found" << endl;
            }
        }
        
        delete bst;
    }
    
    // Test Case 4: Deletion Test Cases
    testBST("Deletion Test Cases");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        
        // Build BST
        int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
        for (int val : values) {
            bst->insert(val);
        }
        
        cout << "Initial BST:" << endl;
        bst->visualize();
        
        // Delete leaf node
        cout << "Deleting leaf node (10):" << endl;
        bst->deleteNode(10);
        bst->visualize();
        
        // Delete node with one child
        cout << "Deleting node with one child (20):" << endl;
        bst->deleteNode(20);
        bst->visualize();
        
        // Delete node with two children
        cout << "Deleting node with two children (30):" << endl;
        bst->deleteNode(30);
        bst->visualize();
        
        delete bst;
    }
    
    // Test Case 5: Single Node Tree
    testBST("Single Node Tree");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>(42);
        
        cout << "BST with single node:" << endl;
        bst->visualize();
        
        cout << "In-order: ";
        bst->inOrder();
        cout << endl;
        
        cout << "Smallest: " << bst->findSmallest()->data << endl;
        cout << "Largest: " << bst->findLargest()->data << endl;
        
        cout << "Deleting the only node..." << endl;
        bst->deleteNode(42);
        
        cout << "BST after deletion:" << endl;
        bst->visualize();
        
        delete bst;
    }
    
    // Test Case 6: Empty Tree
    testBST("Empty Tree Operations");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        
        cout << "Empty BST:" << endl;
        bst->visualize();
        
        cout << "Searching for 10 in empty tree: ";
        cout << (bst->existNode(10) ? "Found" : "Not found") << endl;
        
        cout << "Trying to delete from empty tree..." << endl;
        bst->deleteNode(10);
        
        cout << "First insertion (root):" << endl;
        bst->insert(100);
        bst->visualize();
        
        delete bst;
    }
    
    // Test Case 7: Character BST
    testBST("Character BST");
    {
        BinarySearchTree<char>* charBST = new BinarySearchTree<char>();
        
        char chars[] = {'M', 'F', 'S', 'B', 'H', 'P', 'Z', 'A', 'D'};
        cout << "Inserting characters: ";
        for (char c : chars) {
            cout << c << " ";
            charBST->insert(c);
        }
        cout << endl;
        
        cout << "Character BST structure:" << endl;
        charBST->visualize();
        
        cout << "In-order (alphabetical): ";
        charBST->inOrder();
        cout << endl;
        
        cout << "Smallest character: " << charBST->findSmallest()->data << endl;
        cout << "Largest character: " << charBST->findLargest()->data << endl;
        
        delete charBST;
    }
    
    // Test Case 8: Degenerate Tree (becomes a linked list)
    testBST("Degenerate Tree (Linked List)");
    {
        BinarySearchTree<int>* degenerateBST = new BinarySearchTree<int>();
        
        // Insert in ascending order (worst case)
        int ascending[] = {1, 2, 3, 4, 5, 6, 7};
        cout << "Inserting in ascending order: ";
        for (int val : ascending) {
            cout << val << " ";
            degenerateBST->insert(val);
        }
        cout << endl;
        
        cout << "Degenerate BST (right-skewed):" << endl;
        degenerateBST->visualize();
        
        cout << "In-order: ";
        degenerateBST->inOrder();
        cout << endl;
        
        delete degenerateBST;
        
        // Insert in descending order
        BinarySearchTree<int>* leftSkewed = new BinarySearchTree<int>();
        int descending[] = {7, 6, 5, 4, 3, 2, 1};
        cout << "Inserting in descending order: ";
        for (int val : descending) {
            cout << val << " ";
            leftSkewed->insert(val);
        }
        cout << endl;
        
        cout << "Degenerate BST (left-skewed):" << endl;
        leftSkewed->visualize();
        
        delete leftSkewed;
    }
    
    // Test Case 9: Duplicate Handling
    testBST("Duplicate Value Handling");
    {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        
        // Insert values with duplicates
        int values[] = {10, 5, 15, 5, 10, 15, 3, 7};
        cout << "Inserting values (with duplicates): ";
        for (int val : values) {
            cout << val << " ";
            bst->insert(val);
        }
        cout << endl;
        
        cout << "BST structure (duplicates go right):" << endl;
        bst->visualize();
        
        cout << "In-order traversal: ";
        bst->inOrder();
        cout << endl;
        
        delete bst;
    }
    
    // Test Case 10: Large BST Performance Test
    testBST("Performance Test (Larger BST)");
    {
        BinarySearchTree<int>* largeBST = new BinarySearchTree<int>();
        
        // Insert a balanced set of values
        int balancedValues[] = {50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93};
        cout << "Inserting balanced values: ";
        for (int val : balancedValues) {
            cout << val << " ";
            largeBST->insert(val);
        }
        cout << endl;
        
        cout << "Large BST structure:" << endl;
        largeBST->visualize();
        
        cout << "In-order traversal: ";
        largeBST->inOrder();
        cout << endl;
        
        // Test multiple deletions
        cout << "Deleting 25, 75, 50..." << endl;
        largeBST->deleteNode(25);
        largeBST->deleteNode(75);
        largeBST->deleteNode(50);
        
        cout << "BST after deletions:" << endl;
        largeBST->visualize();
        
        delete largeBST;
    }
    
    cout << "\n=== ALL BINARY SEARCH TREE TEST CASES COMPLETED ===" << endl;
    return 0;
}
