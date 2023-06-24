#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
int calc_median(int a, int b, int c) {
	// Checking for b
    if ((a < b && b < c) || (c < b && b < a))
       return b;
 
    // Checking for a
    else if ((b < a && a < c) || (c < a && a < b))
       return a;
 
    else
       return c;
}

void Quicksort_midpoint(int numbers[], int i, int k) {		//i is  lowIndex, k is highIndex
	// Pick middle element as pivot
	int lowIndex = i;
	int highIndex = k;
	int pivot = calc_median(numbers[i], numbers[(i + (k-i))/2], numbers[k] );
	int temp = 0;

	bool done = false;

	if(lowIndex >= highIndex)	// Base case: If the partition size is 1 or zero elements, then the partition is already sorted
		return;

	while(!done) {
		// Increment lowIndex while numbers[lowIndex] < pivot
		while(numbers[lowIndex] < pivot) {
			lowIndex++;
		}
		// Decrement highIndex while pivot < numbers[highIndex]
		while(pivot < numbers[highIndex]) {
			highIndex--;
		}
		 /* If zero or one elements remain, then all numbers are 
		 partitioned. Return highIndex.
		 */ 
		if(lowIndex >= highIndex)
			done = true;
		else {
			// Swap numbers[lowIndex] and numbers[highIndex]
			temp = numbers[lowIndex];
			numbers[lowIndex] = numbers[highIndex];
			numbers[highIndex] = temp;

			//Update lowIndex and highIndex
			lowIndex++;
			highIndex--;
		}
	}
	Quicksort_midpoint(numbers, i, highIndex);
	Quicksort_midpoint(numbers, highIndex + 1, k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
	// Pick middle element as pivot
	int lowIndex = i;
	int highIndex = k;
	int midpoint = lowIndex + (highIndex - lowIndex) / 2;	
	int pivot = numbers[midpoint];
	int temp = 0;

	bool done = false;

	if(lowIndex >= highIndex)	// Base case: If the partition size is 1 or zero elements, then the partition is already sorted
		return;
	while(!done) {
		// Increment lowIndex while numbers[lowIndex] < pivot
		while(numbers[lowIndex] < pivot) {
			lowIndex++;
		}
		// Decrement highIndex while pivot < numbers[highIndex]
		while(pivot < numbers[highIndex]) {
			highIndex--;
		}
		 /* If zero or one elements remain, then all numbers are 
		 partitioned. Return highIndex.
		 */ 
		if(lowIndex >= highIndex)
			done = true;
		else {
			// Swap numbers[lowIndex] and numbers[highIndex]
			temp = numbers[lowIndex];
			numbers[lowIndex] = numbers[highIndex];
			numbers[highIndex] = temp;

			//Update lowIndex and highIndex
			lowIndex++;
			highIndex--;
		}
	}
	Quicksort_medianOfThree(numbers, i, highIndex);
	Quicksort_medianOfThree(numbers, highIndex + 1, k);
}

void InsertionSort(int numbers[], int numbersSize) {
	int i = 0; 
	int j = 0;
	int temp = 0; //temporary variable for swap

	for(i = 1; i < numbersSize; i++) {
		j = i;
		while(j > 0 && numbers[j] < numbers[j-1]) {
			temp = numbers[j];
			numbers[j] = numbers[j-1];
			numbers[j-1] = temp;
			j--; 
		}
	}
}
int main() {
	
	int array1[NUMBERS_SIZE], array2[NUMBERS_SIZE], array3[NUMBERS_SIZE];
	fillArrays(array1, array2, array3);

	clock_t Start = clock();
	Quicksort_midpoint(array1, 0, NUMBERS_SIZE);
	clock_t End = clock();
	int elapsedTime1 = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "The run time of Quicksort_midpoint is: " << elapsedTime1 << " milliseconds" << endl;
	clock_t Start1 = clock();
	Quicksort_medianOfThree(array2, 0, NUMBERS_SIZE);
	clock_t End1 = clock();
	int elapsedTime2 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "The run time of Quicksort_medianOfThree is: " << elapsedTime2 << " milliseconds" << endl;
	clock_t Start2 = clock();
	InsertionSort(array3, NUMBERS_SIZE);
	clock_t End2 = clock();
	int elapsedTime3 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "The run time of InsertionSort is: " << elapsedTime3 << " milliseconds" << endl;

	return 0;
}