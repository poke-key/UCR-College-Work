#ifndef VENDINGMACHINE_H_
#define VENDINGMACHINE_H_

#include <iostream>
using namespace std;

class VendingMachine {

    public:
		VendingMachine();
		void Purchase(int amount);
		int GetInventory();
		void Restock(int amount);
		void Report();

    private:
        int bottles;
};

#endif /* VENDINGMACHINE_H_ */