#ifndef __NODE_H
#define __NODE_H

#include <string>

using namespace std;

class Node {

  friend class Tree;

private:
  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

  // Add additional functions/variables here. Remember, you may not add any
  // Node * or string variables.
public: 
    Node();
    Node(const string &, Node *);
    Node(const string &, const string &);
    bool hasTwoStrings();
    bool isLeaf() ;

};

#endif