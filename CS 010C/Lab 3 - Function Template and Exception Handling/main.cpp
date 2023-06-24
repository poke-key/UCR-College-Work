#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template<typename TheType>
unsigned min_index(const vector<TheType> &vals, unsigned index) {
    unsigned minIndex = index;              // index of minimum value
    for(unsigned int i = index; i < vals.size(); i++) {     // start at the index of the unsorted part
        if(vals.at(i) < vals.at(minIndex)) {
            minIndex = i;                   // set minimum valueindex
        }
    }
    return minIndex;                        // return the index of minimum value
}

template<typename TheType>
void selection_sort(vector<TheType> &vals) {
    unsigned minIndex;
    if ( vals.size() > 0 ) {        // make sure we have elements in the vector
        for(unsigned int i = 0; i < (vals.size() - 1); i++) {   // go until 
            minIndex = min_index(vals, i);      // find the idex of the minimum for the unsorted part
            swap(vals.at(i), vals.at(minIndex));    // swap the two values
        }
    }
}

template<typename TheType>
TheType getElement(vector<TheType> vals, int index) {
    return vals.at(index);      // return value at the index.
} 

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}
int main() {
    srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
            // make sure idex is valid or else throw out of raange exception.
            if ( index < 0 || index > (int)(vals.size() -1) )
                throw std::out_of_range("");
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (const std::out_of_range& e) {
            // Prints the error message passed by throw statement
            cout << "out of range exception occured" << endl;
        }
    }
    return 0; 
}