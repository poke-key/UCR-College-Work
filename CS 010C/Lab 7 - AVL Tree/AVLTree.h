#include "Node.h"

#ifndef __AVL_H__
#define __AVL_H__

class AVLTree {

    private:
        Node* root;
        void printBalanceFactors(Node *);
        Node* findUnbalancedNode();
        Node* rotateLeft(Node* );
        Node* rotateRight(Node* );
        void visualizeTree(ofstream &, Node *);
        Node* searchHelper(Node * node, const string &data);
        void printHelper(Node*);
        Node* AVLTreeRebalance(Node*) ;
        int AVLTreeGetBalance(Node*) ;
        Node* AVLTreeRotateRight(Node *) ;
        Node* AVLTreeRotateLeft(Node *) ;
        bool AVLTreeSetChild(Node* parent, string whichChild, Node* child) ;
        bool AVLTreeReplaceChild(Node*, Node*, Node*) ;
        void AVLTreeUpdateHeight(Node*) ;

    public:
        AVLTree();
        ~AVLTree();
        AVLTree& operator=(const AVLTree &rhs);
        void deleteNode(Node *tree);
        void copyNodes(Node* source, Node* destination);
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors();
        void visualizeTree(const string &);
        Node* find(const string &key) const;
};

#endif