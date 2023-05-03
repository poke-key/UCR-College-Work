#include <iostream>

#include "VendingMachine.h"
using namespace std;

int main() {
	/* Type your code here */
	int amount;
	VendingMachine machine;
	
	cin >> amount;
	machine.Purchase(amount);
	cin >> amount;
	machine.Restock(amount);
	machine.Report();
}