#include <iostream>
#include <string>
using namespace std;
#include "BSTree.h"

BSTree::BSTree() {  //constructor
    root = nullptr;
}
BSTree::~BSTree() {     //destructor
    deleteNode(root);
}
/*assignment operator overload 
check if same object
delete all nodes
copy node from RHS
*/
BSTree& BSTree::operator=(const BSTree &rhs) {  
    if(this == &rhs)    
        return *this;
    deleteNode(root);
    root=nullptr;
    if(rhs.root) {
        root = new Node(rhs.root -> data, rhs.root -> count);
        copyNodes(rhs.root, root);
    }
    return *this;
}
/*
copy recursively the left tree and then right tree
*/
void BSTree::copyNodes(Node* source, Node* destination) {
    if (source->ltree) {
        destination->ltree = new Node(source->ltree->data, source->ltree->count);
        destination->ltree->parent = destination;
        copyNodes(source->ltree, destination->ltree);
    }
    if (source->rtree) {
        destination->rtree = new Node(source->rtree->data, source->rtree->count);
        destination->rtree->parent = destination;
        copyNodes(source->rtree, destination->rtree);
    }
}
/*
call delete node recursively for left tree and right tree
*/
void BSTree::deleteNode(Node *tree) {
    if (!tree) {
        return;
    }
    deleteNode(tree->ltree);
    deleteNode(tree->rtree);
    delete tree;
}
/* Mutators */
/* Insert an item into the binary search tree. 
    Be sure to keep BST properties. 
    When an item is first inserted into the tree the count should be set to 1. 
    When adding a duplicate string (case sensitive), rather than adding another node, 
    the count variable should be incremented 
    */
void BSTree::insert(const string &newString) {
    Node* currNode;
    if((currNode = find(newString))) {
        currNode->count++;
        return;
    }
    if (!root) {
        root = new Node(newString); //if root is null, allocate a new root
    }
    else {
        currNode = root;
        while (currNode) {
            if (newString < currNode->data) {
                if (!currNode->ltree) {
                    currNode->ltree = new Node(newString);
                    currNode->ltree->parent = currNode;
                    currNode = nullptr;
                }
                else {
                    currNode = currNode->ltree;
                }
            }
            else {
                if (!currNode->rtree) {
                    currNode->rtree = new Node(newString);
                    currNode->rtree->parent = currNode;
                    currNode = nullptr;
                }
                else {
                    currNode = currNode->rtree;
                }
            }
        }
    }
}
/* Remove a specified string from the tree. 
    Be sure to maintain all binary search tree properties. 
    If removing a node with a count greater than 1, just decrement the count, otherwise, 
    if the count is simply 1, remove the node. 
    You MUST follow the remove algorithm shown in the slides and discussed in class or else 
    your program will not pass the test functions. 
    When removing, 
        if removing a leaf node, simply remove the leaf. Otherwise, 
        if the node to remove has a left child, replace the node to remove with the largest 
        string value that is smaller than the current string to remove 
        (i.e. find the largest value in the left subtree of the node to remove). 
        If the node has no left child, replace the node to remove with the smallest value 
        larger than the current string to remove 
        (i.e. find the smallest value in the right subtree of the node to remove. 
    */
void BSTree::remove(const string &key) {
    Node* parent = nullptr;
    Node* currNode = root;
    if((currNode = find(key))) {
        if(currNode->count > 1) {
            currNode->count--;
            return;
        }  
    }
    currNode = root;
    while (currNode) { // Search for node
        if (currNode->data == key) { // Node found 
            if (!currNode->ltree && !currNode->rtree) { // Remove leaf
                if (!parent) {  // Node is root
                    root = nullptr;
                    delete currNode;
                }
                else if (parent->ltree == currNode) {
                    parent->ltree = nullptr;
                    delete currNode;           //delete zombie leaf node
                }
                else {
                    parent->rtree = nullptr;
                    delete currNode;           //delete zombie leaf node
                }
            }
            else if (currNode->ltree) {                // Remove node with only left child
                Node *sucNode = currNode->ltree;
                while (sucNode->rtree)
                    sucNode = sucNode->rtree;
                string successorData = sucNode->data;
                int successorCount = sucNode->count;
                sucNode->count = 1;
                remove(sucNode->data);   // Remove successor 
                currNode->data = successorData; //Assign cur's data with successorData
                currNode->count = successorCount ;
            }
            else if (!currNode->ltree) {                // Remove node with only right child
                // Find successor (rightmost child of left subtree)
                Node *sucNode = currNode->rtree;
                while (sucNode->ltree)
                    sucNode = sucNode->ltree;
                string successorData = sucNode->data;
                int successorCount = sucNode->count;
                sucNode->count = 1;
                remove(sucNode->data);   // Remove successor                  
                currNode->data = successorData; //Assign cur's data with successorData
                currNode->count = successorCount ;
            }
            return; // Node found and removed
        }
        else 
            if (key > currNode->data ) { // Search rtree
                parent = currNode;
                currNode = currNode->rtree;
            }
            else {                     // Search left
                parent = currNode;
                currNode = currNode->ltree;
            }
    }
    return; // Node not found
}
/*
Find returns the pointer to the node instead of boolean
if match with the key is found. Or else it continues the 
search, first left then right(non-recursively).
*/
Node* BSTree::find(const string &key) const {
    Node* currNode = root;
    while (currNode) {
        if (key == currNode->data) {
            return currNode; // Found
        }
        else if (key < currNode->data) {
            currNode = currNode->ltree;
        }
        else {
            currNode = currNode->rtree;
        }
    }
    return nullptr; // Not found
}

/* Accessors */
/* Search for a string in the binary search tree. 
    It should return true if the string is in the tree, and false otherwise. 
    */
bool BSTree::search(const string &key) const {
    Node* currNode = root;
    while (currNode) {
        if (key == currNode->data) {
            return true; // Found
        }
        else if (key < currNode->data) {
            currNode = currNode->ltree;
        }
        else {
            currNode = currNode->rtree;
        }
    }
    return false; // Not found

}
/* Find and return the largest value in the tree. Return an empty string if the tree is empty */
string BSTree::largest() const {
    if(!root) {
        return "";
    }
    Node* currNode = root;
    while(currNode->rtree) {
        currNode = currNode->rtree;
    }
    return currNode->data;
}
/* Find and return the smallest value in the tree. Return an emtpy string if the tree is empty */
string BSTree::smallest() const {
    if(!root) {
        return "";
    }
    Node* currNode = root;
    while(currNode->ltree) {
        currNode = currNode->ltree;
    }
    return currNode->data;

}
/* Compute and return the height of a particular string in the tree. 
    The height of a leaf node is 0 (count the number of edges on the longest path). 
    Return -1 if the string does not exist. 
    */
int BSTree::height(const string&data) const {
    Node* tree = find(data);
    return heightHelper(tree); //call to height helper to return the height
}
/*
recursive function that calculates the height rooted at a particular node
returns the max+1 of the left or right side 
*/
int BSTree::heightHelper(Node* tree) const { 
    if (!tree) {
        return -1;
    }
    int leftHeight = heightHelper(tree->ltree);
    int rightHeight = heightHelper(tree->rtree);
    return 1 + max(leftHeight, rightHeight);
}
/*
prints the tree in Preorder, Inorder, and Postorder fashion.
*/
void BSTree::print() const {
    cout << "Preorder = ";
    preOrder(root);
    cout << endl;
    cout << "Inorder = ";
    inOrder(root);
    cout << endl;
    cout << "Postorder = ";
    postOrder(root);
    cout << endl;
    
}
/*
calls recursive preOrder
*/
void BSTree::preOrder() const { 
    preOrder(root);
}
/* Printing */
/* For all printing orders, each node should be displayed as follows:
    <string> (<count>)
    e.g. goodbye(1), Hello World(3)
    */
void BSTree::preOrder(Node* tree) const {
    if(tree == nullptr) {
        return;
    }
    
    cout << tree->data << "(" << tree->count << "), " ;
    preOrder(tree->ltree);
    preOrder(tree->rtree);
}
/*
calls recursive postOrder
*/
void BSTree::postOrder() const {
    postOrder(root);
}
void BSTree::postOrder(Node* tree) const {
    if(tree == nullptr) {
        return;
    }
    postOrder(tree->ltree);
    postOrder(tree->rtree);
    cout << tree->data << "(" << tree->count << "), " ;
}
/*
calls recursive inOrder
*/
void BSTree::inOrder() const { 
    inOrder(root);
}
void BSTree::inOrder(Node* tree) const {
    if(tree == nullptr) {
        return;
    }
    inOrder(tree->ltree);
    cout << tree->data << "(" << tree->count << "), " ;
    inOrder(tree->rtree);

}