#include "Node.h"

Node::Node() {
    small = "";
    large = "";
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(const string &small, const string &large) : Node() {
    this->small = small;
    this->large = large;
}

Node::Node(const string &key, Node* parent) {
    small = key;
    large = "";
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    this->parent = parent;
}
bool Node::isLeaf()
{
    if (!left && !middle && !right)
        return true;
    return false;
}

bool Node::hasTwoStrings() {
    if(small != "" && large != "") {
        return true;
    }
    return false;
}