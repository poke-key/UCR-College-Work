#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "AVLTree.h"

AVLTree::AVLTree() {    //constructor
    root = nullptr;
}

AVLTree::~AVLTree() {   //destructor
   deleteNode(root);
}
/*assignment operator overload 
check if same object
delete all nodes
copy node from RHS
*/
AVLTree& AVLTree::operator=(const AVLTree &rhs) {
    if(this == &rhs)    
        return *this;
    deleteNode(root);
    root=nullptr;
    if(rhs.root) {
        root = new Node(rhs.root->data, rhs.root->count);
        copyNodes(rhs.root, root);
    }
    return *this;
}
/*
copy recursively the left tree and then right tree
*/
void AVLTree::copyNodes(Node* source, Node* destination) {
    if (source->left) {
        destination->left = new Node(source->left->data, source->left->count);
        destination->left->parent = destination;
        copyNodes(source->left, destination->left);
    }
    if (source->right) {
        destination->right = new Node(source->right->data, source->right->count);
        destination->right->parent = destination;
        copyNodes(source->right, destination->right);
    }
}
/*
call delete node recursively for left tree and right tree
*/
void AVLTree::deleteNode(Node *tree) {
    if (!tree) 
        return;
    deleteNode(tree->left);
    deleteNode(tree->right);
    delete tree;
}

void AVLTree::insert(const string &data) {
    if (root == nullptr ) {     //when there is no root, you insert as root
      root = new Node(data);
      root->balanceFactor = -1;
      return;
    }

    Node* currNode;
    if((currNode = find(data))) {
        currNode->count++;
        return;
    }

   currNode = root;
   Node* newNode = new Node(data);
   while (currNode != nullptr) {
      if ( newNode->data < currNode->data) {
         if (currNode->left == nullptr) {
            currNode->left = newNode;
            newNode->parent = currNode;
            currNode = nullptr;
         }
         else {
            currNode = currNode->left;
         }
      }
      else {
         if ( currNode->right == nullptr ) {
            currNode->right = newNode;
            newNode->parent = currNode;
            currNode = nullptr;
         }
         else
            currNode = currNode->right;
      }
   }

   newNode = newNode->parent;
   while (newNode  != nullptr ) {
      AVLTreeRebalance(newNode);
      newNode = newNode->parent;
   }
}

/*
Returns the balance factor of a node.
*/
int AVLTree::balanceFactor(Node* node) {
	int leftHeight = 0, rightHeight = 0;
	if (node == nullptr) {
		return -1;
	}
	
	if (node->left) {
		leftHeight = node->left->height;
	}
	else {
		leftHeight = -1;
	}
	
	if (node->right) {
		rightHeight = node->right->height;
	}
	else {
		rightHeight = -1;
	}
	
	return leftHeight - rightHeight;
}

/*
Searches for certain key in the node. If not found, traverses left if smaller or traverses right if larger.
*/
Node* AVLTree::find(const string &key) const {
    Node* currNode = root;
    while (currNode) {
        if (key == currNode->data) {
            return currNode; // Found
        }
        else if (key < currNode->data) {
            currNode = currNode->left;
        }
        else {
            currNode = currNode->right;
        }
    }
    return nullptr; // Not found
}
/*
When a node is updated, inserted, or removed this function is called to rebalance the tree through rotations so that it remains a valid AVL Tree. 
*/
Node* AVLTree::AVLTreeRebalance(Node* node) {
   AVLTreeUpdateHeight(node);
   if (AVLTreeGetBalance(node) == -2) {
      if (AVLTreeGetBalance(node->right) == 1) {
         // Double rotation case.
         AVLTreeRotateRight(node->right);
      }
      return AVLTreeRotateLeft(node);
   }
   else if (AVLTreeGetBalance(node) == 2) {
      if (AVLTreeGetBalance(node->left) == -1) {
         // Double rotation case.
         AVLTreeRotateLeft(node->left);
      }
      return AVLTreeRotateRight(node);
   }        
   return node;
}

/*
Updates the nodes height during rebalancing the AVL tree.
*/
void AVLTree::AVLTreeUpdateHeight(Node* node) {
   int leftHeight = -1;
   if (node->left != nullptr)
      leftHeight = node->left->height;
   int rightHeight = -1;
   if (node->right != nullptr)
      rightHeight = node->right->height;
   node->height = max(leftHeight, rightHeight) + 1;
}
/*
Used to get the balance factor of a node.
*/
int AVLTree::AVLTreeGetBalance(Node* currNode) {
   int leftHeight = -1;
   if (currNode->left != nullptr)
      leftHeight = currNode->left->height;
   int rightHeight = -1;
   if (currNode->right != nullptr)
      rightHeight = currNode->right->height;
   return leftHeight - rightHeight;
}
/*
Rotate right for rebalancing the AVL Tree.
*/
Node *AVLTree::AVLTreeRotateRight(Node *node) {
   Node *leftRightChild = node->left->right;
   if (node->parent != nullptr)
      AVLTreeReplaceChild(node->parent, node, node->left);
   else { // node is root
      root = node->left;
      root->parent = nullptr;
   }
   AVLTreeSetChild(node->left, "right", node);
   AVLTreeSetChild(node, "left", leftRightChild);
   return node;
}
/*
Rotate left for rebalancing the AVL Tree.
*/
Node *AVLTree::AVLTreeRotateLeft(Node *node) {
   Node *rightLeftChild = node->right->left;

   if (node->parent != nullptr)
      AVLTreeReplaceChild(node->parent, node, node->right);
   else { // node is root
      root = node->right ;
      root->parent = nullptr;
   }
   AVLTreeSetChild(node->right, "left", node);
   AVLTreeSetChild(node, "right", rightLeftChild);

   return node;
}
/*
Setting the new child and updating the height after the rotation either left or right.
*/
bool AVLTree::AVLTreeSetChild(Node* parent, string whichChild, Node* child) {
   if (whichChild != "left" && whichChild != "right")   
      return false;

   if (whichChild == "left")
      parent->left = child;
   else
      parent->right = child;
   if (child != nullptr)
      child->parent = parent;

   AVLTreeUpdateHeight(parent);
   return true;
}
/*
Replaces the child during the rotation of the nodes.
*/
bool AVLTree::AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild) {
   if (parent->left == currentChild)
      return AVLTreeSetChild(parent, "left", newChild);
   else if (parent->right == currentChild)
      return AVLTreeSetChild(parent, "right", newChild);
   return false;
}
/*
prints the data contained in the Node and the balance factor through calling printHelper.
*/
void AVLTree::printBalanceFactors() {
    if (root) {
        printHelper(root);  
        cout << endl;
    }
}

void AVLTree::printHelper(Node *currNode) {
    if (!currNode )                     // base case
        return;
    
    printHelper(currNode->left);
    cout << currNode->data << "(" << balanceFactor(currNode) <<"), ";
    printHelper(currNode->right);
}

void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS, root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n) {
        if(n->left) {
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right) {
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}