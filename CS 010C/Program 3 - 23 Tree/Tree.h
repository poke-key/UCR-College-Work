#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node *root;

public:
  Tree();
  ~Tree();
  Tree& operator=(const Tree &rhs);
  void copyNodes(Node* source, Node* destination);
  void deleteNode(Node *tree);
  void insert(const string &);
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  void  remove(const string &);
  bool search (const string &) const;
  Node* find(const string &) const;


private:
  // Add additional functions/variables here
  void preOrder( Node*) const;
  void inOrder(Node* ) const;
  void postOrder( Node*) const;
  bool searchHelper(Node* currNode, const string &key) const;
  Node* findHelper(Node* currNode, const string &key) const;
  Node* splitLeaf(const string &key, Node* currentNode, Node* parent);
  Node *split3Node(Node* currentNode) ;
  void pushup(Node* currentNode) ;
  Node* BTreeInsert(Node* currNode, const string &key) ;
  void BTreeInsertIntoLeaf(Node* currNode, const string &key);
};

#endif