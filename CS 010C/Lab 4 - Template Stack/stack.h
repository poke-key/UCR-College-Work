#ifndef stack_h
#define stack_h
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> class stack {
    private:
        static const int MAX_SIZE = 20;
        T data[MAX_SIZE];
        int size;

    public:
        stack();
        void push(T);
        void pop() ;
        void pop_two() ;
        T top() ;
        bool empty();
};

template <typename T> 
stack<T>::stack() {
    size = 0;
}

template <typename T> 
void stack<T>::push(T val) {
    try {
        if(size >= MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        data[size] = val;
        size++;

    }
    catch (const overflow_error& e) {
        cout << e.what();
    }
}

template <typename T> 
void stack<T>::pop() {
    try {
        if(empty()) {
            throw out_of_range("Called pop on empty stack.");
        }
        size--;
    }            
    catch (const out_of_range& e) {
        cout << e.what();
    }
}

template <typename T> 
void stack<T>::pop_two() {
    try {
        if(empty()) {
            throw out_of_range("Called pop_two on empty stack.");
        }
        if(size == 1) {
            throw out_of_range("Called pop_two on a stack of size 1.");
        }
        size -= 2;
    }            
    catch (const out_of_range& e) {
        cout << e.what() << endl;
        exit(1);
    }
}

template <typename T> 
T stack<T>::top() { 
    try {
        if(empty()) {
            throw underflow_error("Called top on empty stack.");
        }
        return data[size - 1];
    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
        exit(1);
    }
}

template <typename T> 
bool stack<T>::empty() {
    if(!size) {
        return true;
    }
    return false;
}

#endif



