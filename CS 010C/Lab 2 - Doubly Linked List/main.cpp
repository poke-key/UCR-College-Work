#include <iostream>
using namespace std;
#include "IntList.h"
int main() {
    IntList mylist;
    cout << mylist.empty() << endl;
    mylist.push_back(10);
    mylist.push_back(11);
    mylist.push_front(5);
    mylist.push_front(3);
    cout << mylist << endl;
    //cout << "before print reverse" << endl;
    mylist.printReverse();
    mylist.pop_back();
    mylist.printReverse();
    mylist.pop_front();
    mylist.printReverse();

}
