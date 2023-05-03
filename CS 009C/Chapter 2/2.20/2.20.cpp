#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   ifstream inFS;
   string inputFile;
   string outputFile;
   vector<int> myInt;
   int num;
   char comma;
   int sum = 0;
   unsigned int i;
   int average = 0;
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
   // Create input stream and open input csv file.
   inFS.open(inputFile);
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   if (!inFS.is_open()) {
      cout << inputFile << ": could not be opened" << endl;
      return 1;
   }
   // Read in integers from input file to vector.
   inFS >> num;
   while (!inFS.fail()) {
      inFS >> comma;
      myInt.push_back(num);
      inFS >> num;
   }
   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   for(i = 0; i < myInt.size(); i++) {
      sum += myInt.at(i);
   }
   average = sum/myInt.size();
   // Convert each value within vector to be the difference between the original value and the average.
   for(i = 0; i < myInt.size(); i++) {
      myInt.at(i) -= average;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << outputFile << ": could not be opened" << endl;
      return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(i = 0; i < myInt.size(); i++) {
      if(myInt.size() - 1 == i) {
         outFS << myInt.at(i);
      }
      else {
         outFS << myInt.at(i) << ",";
      }
   }
//   outFS << endl;
   // Close output stream.
   outFS.close();
   return 0;
}