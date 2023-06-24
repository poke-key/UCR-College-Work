#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() {  
  numItems = 0;
}

Heap& Heap::operator=(const Heap& other) {
  if (this == &other)   
    return *this;
  
  // Deallocate the current heap
  for (int i = 0; i < numItems; i++) 
    delete arr[i];
  
  numItems = 0;

  // Copy the other heap
  for (int i = 0; i < other.numItems; i++) {
    PrintJob* copy = new PrintJob(other.arr[i]->getPriority(),
                                  other.arr[i]->getJobNumber(),
                                  other.arr[i]->getPages()); // Create new print job 
    arr[i] = copy;
  }
  numItems = other.numItems;
  return *this;
}

Heap::~Heap() {
  for (int i = 0; i < numItems; i++) 
    delete arr[i]; //delete 
  
  numItems = 0;
}

/*
Inserts a PrintJob to the heap without
violating max-heap properties.
}
*/
void Heap::enqueue(PrintJob*  newPrintJob) {
  if ( numItems == MAX_HEAP_SIZE ) //if we are at MAX_HEAP_SIZE-1, we can still add
    return; // cannot return anything

  arr[numItems] = newPrintJob;
  bubbleUp(numItems);
  numItems++;
}

void Heap::bubbleUp(int nodeIndex) {
  int parentIndex ;
   while (nodeIndex > 0) {
      parentIndex = (nodeIndex - 1)/2;
      if (arr[nodeIndex]->getPriority() <= arr[parentIndex]->getPriority())
         return;
      else {
         swap(arr[nodeIndex], arr[parentIndex]);
         nodeIndex = parentIndex;
      }
   }
}

/*
Removes the node with highest priority from the heap. 
Follow the algorithm on priority-queue slides.
*/
void Heap::dequeue () {
  if (!numItems) {  // = 0
    return;
  }
  if ( numItems > 1) {
    arr[0] = arr[numItems-1];
    trickleDown(0);
  }
  numItems--;
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest () {
  if ( numItems )
    return arr[0];
  return 0;
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print () const {
    PrintJob* printJob;

    if (numItems) {
    printJob = arr[0];
    cout << "Priority: " << printJob->getPriority() 
                    << ", Job Number: " << printJob->getJobNumber() 
                    << ", Number of Pages: " << printJob->getPages() << endl ;
    }
      else {
        cout << "The heap is empty." << endl;
    }
}

void Heap::trickleDown(int nodeIndex) {
  int childIndex = 2 * nodeIndex + 1;
  int priority = arr[nodeIndex]->getPriority();

   while (childIndex < numItems) {
      // Find the max among the node and all the node's children
      int maxPriority = priority;
      int maxIndex = -1;
      for (int i = 0; (i < 2) && ((i + childIndex) < numItems); i++) {
         if (arr[i + childIndex]->getPriority() > maxPriority ) {
            maxPriority = arr[i + childIndex]->getPriority();
            maxIndex = i + childIndex;
         }
      }

      if (maxPriority == priority) {
         return;
      }
      else {
         swap(arr[nodeIndex], arr[maxIndex]);
         nodeIndex = maxIndex;
         childIndex = 2 * nodeIndex + 1;
      }
   }
}