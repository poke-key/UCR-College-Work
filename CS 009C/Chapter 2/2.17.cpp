#include <iostream>
#include <cstdlib>
using namespace std;

string CoinFlip() {
   if(rand() % 2 == 0) {
      return ("Tails");
   }
   else {
      return ("Heads");
   }
}

int main() {
   int count;
   
   srand(2);  // Unique seed

   cin >> count;
   while(count) {
      cout << CoinFlip() << endl;
      count--;
   }

   return 0;
}
