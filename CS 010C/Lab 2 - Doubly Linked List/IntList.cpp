#include <iostream>
#include "IntList.h"
IntList::IntList() {
    dummyHead = new IntNode;
    dummyTail = new IntNode;
    dummyHead->data = 0;
    dummyTail->data = 0;
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    dummyHead->prev = 0;
    dummyTail->next = 0;
}
IntList::~IntList() {
    delete dummyHead;
    delete dummyTail;
}
void IntList::push_front(int value) {
    IntNode *newNode = new IntNode;
    newNode->data = value;
    IntNode *firstNode = dummyHead->next;
    newNode->next = dummyHead->next;
    newNode->prev = dummyHead;
    dummyHead->next = newNode;
    firstNode->prev = newNode;

}
void IntList::pop_front() {
    if ( !empty() ) {
    IntNode *tempNode = dummyHead->next;
    dummyHead->next = tempNode->next;
    tempNode->next->prev = dummyHead; 
    }
}
void IntList::push_back(int value) {
    IntNode *newNode = new IntNode;
    newNode->data = value;
    newNode->prev = dummyTail->prev;
    newNode->next = dummyTail;
    dummyTail->prev->next = newNode;
    dummyTail->prev = newNode;
}
void IntList::pop_back() {
    if ( !empty() ) {
        IntNode *tempNode = dummyTail->prev;
        dummyTail->prev = tempNode->prev;
        tempNode->prev->next = dummyTail;
    }
}
bool IntList::empty() const {
    if(dummyHead->next == dummyTail) {
        return true;
    }
    return false;
}
ostream & operator<<(ostream &out, const IntList &rhs) {
    for (IntNode *curr = rhs.dummyHead->next; curr != rhs.dummyTail; curr = curr->next) {
        out << curr->data;
        if (curr->next != rhs.dummyTail) {
            out << " ";
        }
    }
    return out;
}

void IntList::printReverse() const {
    IntNode *tempNode = dummyTail->prev;
    while (tempNode != dummyHead) {
        cout << tempNode->data << " ";
        tempNode = tempNode->prev;
    }
    cout << endl;
}

