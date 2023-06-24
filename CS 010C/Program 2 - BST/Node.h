#ifndef __NODE_H__
#define __NODE_H__

class Node {
    public: 
        Node(string data); //constructor
        Node(string data, int count);
        Node& operator=(const Node &rhs); //copy constructor
        Node* ltree; //left child
        Node* rtree; //right child
        Node* parent; //parent node
        int count;
        string data;
};

#endif