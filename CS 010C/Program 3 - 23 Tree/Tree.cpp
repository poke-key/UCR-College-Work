#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree( ) {     //constructor
    root = nullptr;
}
Tree::~Tree( ) {        //destructor
    deleteNode(root);
}
/*assignment operator overload 
check if same object
delete all nodes
copy node from RHS
*/
Tree& Tree::operator=(const Tree& rhs) {
    if (this == &rhs)
        return *this;
    deleteNode(root);
    root = nullptr;
    if (rhs.root) {
        root = new Node(rhs.root->small, rhs.root->large);
        copyNodes(rhs.root, root);
    }
    return *this;
}
/*
copy recursively the left tree and then right tree
*/
void Tree::copyNodes(Node* source, Node* destination) {
    if (source->left) {
        destination->left = new Node(source->left->small, source->left->large);
        destination->left->parent = destination;
        copyNodes(source->left, destination->left);
    }
    if (source->middle) {
        destination->middle = new Node(source->middle->small, source->middle->large);
        destination->middle->parent = destination;
        copyNodes(source->middle, destination->middle);
    }
    if (source->right) {
        destination->right = new Node(source->right->small, source->right->large);
        destination->right->parent = destination;
        copyNodes(source->right, destination->right);
    }
}
/*
call delete node recursively for left tree and right tree
*/
void Tree::deleteNode(Node *tree) {
    if (!tree) {
        return;
    }
    deleteNode(tree->left);
    deleteNode(tree->middle);
    deleteNode(tree->right);
    delete tree;
}
void Tree::insert(const string &key) {
    if ( !root )    //tree is empty
        root = new Node(key, nullptr) ;
    else
        BTreeInsert(root, key); //call the insert helper function
}
Node* Tree::BTreeInsert(Node* currentNode, const string &key) {
    if ( currentNode->isLeaf()) {
        if ( currentNode->large == "") {          // leaf has only one item
            if ( key > currentNode->small ) {
                currentNode->large = key;
            }
            else {
                currentNode->large = currentNode->small;
                currentNode->small = key;
            }
        }
        else {                  // leaf has two items so needs to be split
            splitLeaf(key, currentNode, currentNode->parent);
            if ( currentNode->parent ) {
                pushup(currentNode) ;
            }
        }
    }
    else {        // not a leaf so continue
        if ( key < currentNode->small) {
            BTreeInsert(currentNode->left, key);        // left insert
        }
        else if ( currentNode->large == "") {
            BTreeInsert(currentNode->right, key);        // right insert
        }
        else {
            if ( key < currentNode->large) {
                BTreeInsert(currentNode->middle, key);        // new item is in the middle
            }
            else {                                              // new item is largets
                BTreeInsert(currentNode->right, key);
            }
        }
    }
    return nullptr;
}

void Tree::pushup(Node* currentNode)  {
    Node* parent = currentNode->parent;
    if ( parent->large == "" ) {           //2-node case
        if ( currentNode->small < parent->small ) {
            parent->large = parent->small;
            parent->small =  currentNode->small;
            parent->middle = currentNode->right;
            parent->middle->parent = parent;
            parent->left = currentNode->left;
            parent->left->parent = parent;
            delete currentNode;
        }
        else {
            parent->large = currentNode->small;
            parent->middle = currentNode->left;
            parent->middle->parent = parent;
            parent->right = currentNode->right;
            parent->right->parent = parent;
            delete currentNode;
        }
    }
    else {                                      //3-node case, requires split and pushup
        currentNode = split3Node(currentNode);
        if ( currentNode->parent ) {
            pushup(currentNode);
        }
    }
}

// splitting a 3-node
Node * Tree::split3Node(Node* currentNode)  {
    Node* parent = currentNode->parent ;
    if ( currentNode->small < parent->small ) {        // key goes left
        parent->left = currentNode ;
        parent->left->parent = parent ;
        Node* temp = new Node(parent->large, parent);
        parent->large = "" ;
        temp->left = parent->middle ;
        temp->left->parent = temp ;
        temp->right = parent->right ;
        temp->right->parent = temp ;
        parent->right = temp ;
        parent->middle = nullptr ;
    }
    else {
        if ( currentNode->small < parent->large) {    // key goes middle
            Node* temp = new Node(parent->small, currentNode);
            temp->left = parent->left ;
            temp->left->parent = temp ;
            temp->right = currentNode->left ;
            temp->right->parent = temp ; 
            parent->left = temp ;
            
            Node* temp1 = new Node(parent->large, currentNode);
            temp1->left = currentNode->right ;             
            temp1->left->parent = temp1 ;
            temp1->right = parent->right ;
            temp1->right->parent = temp1;
            parent->right = temp1 ;

            parent->small = currentNode->small ;
            parent->large = "" ;
            parent->middle = nullptr ;
        }
        else {                              // case when currentNode-> large is > parent-large
            parent->right = currentNode;
            parent->right->parent = parent ;
            Node *temp = new Node(parent->small, parent);
            temp->left = parent->left;
            temp->left->parent = temp;
            temp->right = parent->middle;
            temp->right->parent = temp;
            parent->left = temp;
            parent->small = parent->large ;
            parent->large = "";
            parent->middle = nullptr;
        }
    }
    return parent;
}

/*
Inserting an item into a leaf node.
*/
void Tree::BTreeInsertIntoLeaf(Node* currentNode, const string &key)
{
    if ( key < currentNode->small ) {
        currentNode->large = currentNode->small; //swap small to large if it already has a small and is lesser value.
        currentNode->small = key;
    }
    else {
        currentNode->large = key;
    }
}

/*
Function that splits the leaf to balance the tree.
*/
Node*  Tree::splitLeaf(const string &key, Node* currentNode, Node* parent)  {
    if ( ( currentNode->small == "") || ( currentNode->large == "") ) {
        return nullptr;
    }

    if ( key < currentNode->small ) {
        currentNode->left = new Node(key, currentNode);
        currentNode->right = new Node(currentNode->large, currentNode);
        currentNode->large = "";
    }
    else {
        if ( key < currentNode->large ) {
            currentNode->left = new Node(currentNode->small, currentNode);
            currentNode->right = new Node(currentNode->large, currentNode);
            currentNode->large = "";
            currentNode->small = key;
        }
        else {
            currentNode->left = new Node(currentNode->small, currentNode);
            currentNode->right = new Node(key, currentNode);
            currentNode->small = currentNode->large;
            currentNode->large = "";
        }
    }
    return currentNode;
}

void Tree::preOrder( ) const {
    preOrder(root);
    cout << endl ;
}
void Tree::inOrder( ) const {
    inOrder(root);
    cout << endl ;
}
void Tree::postOrder( ) const {
    postOrder(root);
    cout << endl;
}
void Tree::preOrder(Node *currentNode ) const {
    if (!currentNode)         // base case return
        return;
    
    if ( currentNode->large != "" ) {       // 2 strings case
        cout << currentNode->small << ", " ;
        preOrder(currentNode->left) ;
        cout << currentNode->large << ", ";
        preOrder(currentNode->middle) ;
        preOrder(currentNode->right) ;
    }else {
        cout << currentNode->small << ", ";
        preOrder(currentNode->left) ;
        preOrder(currentNode->middle) ;
        preOrder(currentNode->right) ;
    }
}
void Tree::inOrder(Node *currentNode) const {
    if ( ! currentNode)            //base case return
        return ;

    inOrder(currentNode->left);
    cout << currentNode->small << ", ";
    inOrder(currentNode->middle);

    // There are two strings in the node
    if (currentNode->hasTwoStrings())
    {
        cout << currentNode->large << ", ";
    }
    inOrder(currentNode->right);
}

void Tree::postOrder(Node *currentNode ) const {
    if (!currentNode)             // base case return
        return;

    if (currentNode->hasTwoStrings())
    {
        postOrder(currentNode->left);
        postOrder(currentNode->middle);
        cout << currentNode->small << ", ";
        postOrder(currentNode->right);
        cout << currentNode->large << ", ";
    }
    else
    {
        postOrder(currentNode->left);
        postOrder(currentNode->right);
        cout << currentNode->small << ", ";
    }
}
/*
function removes a node with a specified string by searching and removing the node.
*/
void Tree::remove(const string &str){
    Node* removeNode = find(str); 
    if (!removeNode) {  //node to remove not found
        return;
    }
    if (removeNode->hasTwoStrings()) { //if there are two strings, move large string into small
        if (str == removeNode->small){
            removeNode->small = removeNode->large;
            removeNode->large = "";
        }
        else{
            removeNode->large = ""; //just remove the large
        }
    }
    else { //when the node doesn't have two strings
        Node* parent = removeNode->parent;
        if (parent) {   //has a parent node
            if (parent->left == removeNode) {   //if removed node is parent's left, make it null
                parent->left = nullptr;
                parent->large = parent->right->small;
                parent->right = nullptr;
            }
            else {
                parent->right = nullptr;
                parent->large = parent->small;
                parent->small = parent->left->small;
                parent->left = nullptr;
            }
            delete removeNode;
        }
        else { 
            if (root->left) {       //node is the root as it does not have a parent node.
                Node* newRoot = new Node();
                newRoot->small = root->left->small; //move the two childs into the new root
                newRoot->large = root->right->small;
                root = newRoot;
                delete removeNode;
            } 
            else { 
                root = nullptr;
            }
        }
    }
}

Node* Tree::find(const string &key) const {
    return findHelper(root, key);
}
/*Helper function that searches through left, middle, 
and right nodes in the tree for specific key value.
Returns the actual value found, not a boolean
*/
Node* Tree::findHelper(Node* currNode, const string &key) const {
    if (currNode) {
        if (currNode->small == key || currNode->large == key) {
            return currNode;    //found, returns value
        }
        if (key < currNode->small) {
            return findHelper(currNode->left, key);
        }
        else if ( (currNode->large != "") || (key < currNode->large)) {
            return findHelper(currNode->middle, key);
        }
        else {
            return findHelper(currNode->right, key);
        }
    }
    return nullptr; //not found returns null
}

bool Tree::search(const string &key) const {
    return searchHelper(root, key);
}
/*
Helper function that searches through left, middle, 
and right nodes in the tree for specific key value.
*/
bool Tree::searchHelper(Node* currNode, const string &key) const {
    if (currNode) {
        if (currNode->small == key || currNode->large == key) {    
            return true;    //found
        }
        if (key < currNode->small) {
            return searchHelper(currNode->left, key);
        }
        else if ( (currNode->large != "") || (key < currNode->large)) {
            return searchHelper(currNode->middle, key);
        }
        else {
            return searchHelper(currNode->right, key);
        }
    }
    return false;   //not found
}