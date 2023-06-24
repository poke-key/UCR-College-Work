#include <iostream>
#include <string>
using namespace std;
#include "AVLTree.h"

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree ;

#ifdef DEBUG            // for testing
  AVLTree tree1;

  tree.insert("Adam") ;
  tree.insert("Bui") ;
  tree.insert("Chan") ;
  tree.printBalanceFactors() ;
  tree.insert("Edie") ;
  tree.insert("Dan") ;
  tree.printBalanceFactors() ;
  tree.insert("Carr") ;
  tree.printBalanceFactors() ;
  
  
  tree1.insert("papa") ;
  tree1.insert("quebec") ;
  tree1.insert("alpha") ;
  tree1.insert("hotel") ;
  tree1.insert("india") ;
  tree1.insert("juliet") ;
  tree1.insert("bravo") ;
  tree1.insert("charlie") ;
  tree1.insert("alpha") ;
  tree1.insert("india") ;
  tree1.printBalanceFactors() ;
  return 0;
#endif

  int choice = menu();

  string entry;

  while (choice != 3) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();

    } 
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }

  return 0;
}