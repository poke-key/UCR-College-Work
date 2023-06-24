#include "Node.h"

#ifndef __BSTREE_H__
#define __BSTREE_H__

class BSTree {
    private:
        Node *root;
    public:
        /* Constructors */
        /* Default constructor */
        BSTree();
        ~BSTree();
        BSTree& operator=(const BSTree &rhs);
        void deleteNode(Node *tree);
        void insert(const string &newString);
        void remove(const string &key);
        Node* find(const string &key) const;
        bool search(const string &key) const;
        string largest() const;
        string smallest() const;
        int height(const string&) const;
        int heightHelper(Node* root) const;
        void print() const;
        void preOrder() const;
        void preOrder(Node*) const;
        void postOrder() const;
        void postOrder(Node*) const;
        void inOrder() const;
        void inOrder(Node*) const;
        void copyNodes(Node* src, Node* dest);
};

#endif // __BSTREE_H__