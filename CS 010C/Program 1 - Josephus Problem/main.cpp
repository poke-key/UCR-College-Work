#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string payload;
    Node* next;
};

// function to create Node
//copy the payload into it and return the Node
Node* newNode(string payload) {
    Node* ptr = new Node;   // allocate memory for Node
    ptr->payload = payload; // copy the string
    return ptr;
}

/*
 * The first parameter is the number of  names we need to put 
 * in the circular linked list.
 * This function gets a vector of names as inputand creates a
 * circular linked list and returns the pointer to the head
*/
Node* loadGame(int n, vector<string> names) {
    Node* head = nullptr;
    Node* prev = nullptr;

    // iterate for n names and put them in circular linked list
    for (int i = 0; i < n; ++i) {
        if (head == nullptr) {          // case when cirular node is empty, head is nullptr
            head = newNode(names.at(i));// initialize head specially
            prev = head;                // make prev as head also
        } else {
            prev->next = newNode(names.at(i));     // case when head node is already created
            prev = prev->next;            
        }
    }
    if (prev != nullptr) {
         prev->next = head; // make linked list circular by pointing prev-next back to head
     }
    return head;            // return head of the circular linked list
}

/*
 * function to print payload in the circular linked list, given 
 * the head of the circular linked list*/
void print(Node* start) { // prints list
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl;          // print names from payload
        curr = curr->next;                      // advance to next node
        if (curr == start) {                    // if this is head node again, we are done
            break; // exit circular list
        }
    }
}

Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    Node* curr = start;
    Node* prev = curr;

    while (prev->next != prev) { // exit condition, last person standing
        for (int i = 0; i < k; ++i) { // find kth node
          prev = curr;              // save previous node
          curr = curr->next;        // advance to next node
        }

        prev->next = curr->next;    // delete kth node
        delete curr;                // free memeory of the Node
        curr = prev->next;          // make this node as current
    }

    return curr; // last person standing

}

/* Driver program to test above functions */
int main() {
    int n=1, k=1; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs
    cin >> n >> k;
    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }

    return 0;
}

