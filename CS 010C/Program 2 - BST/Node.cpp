 #include <iostream>
 #include <string>
 using namespace std;
 #include "Node.h"
 
Node::Node(string data) {      //constructor
    this->data = data;
    ltree = nullptr;
    rtree = nullptr;
    parent = nullptr;
    count = 1;
}
Node::Node(string data, int count) {    //copy constructor with data and count, used in tree equal operator
    this->data = data;
    ltree = nullptr;
    rtree = nullptr;
    parent = nullptr;
    this->count = count;
}
Node& Node::operator=(const Node &rhs) { //assignment operator overloading
    if (this == &rhs) //check for same object assignment
        return *this;
    
    data = rhs.data;
    count = rhs.count;
    return *this;
}