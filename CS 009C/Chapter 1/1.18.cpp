#include <iostream>
using namespace std;

int main() {
   int highwayNumber;
   
   cin >> highwayNumber;

  if(highwayNumber < 1 ||  highwayNumber > 999)
      cout << highwayNumber << " is not a valid interstate highway number." << endl;
  if( highwayNumber > 0 && highwayNumber < 100) {
      cout << "I-" << highwayNumber << " is primary, going "; 
      if(highwayNumber % 2 == 0) 
         cout << "east/west." << endl;
      else 
         cout << "north/south." << endl;
   }
   if( highwayNumber > 100 && highwayNumber < 1000) {
      // is auxiliary, serving I-90, going east/west.
      if( highwayNumber % 100 == 0)
          cout << highwayNumber << " is not a valid interstate highway number." << endl;
      else {
         cout << "I-" << highwayNumber << " is auxiliary, serving ";
         cout << "I-" << highwayNumber % 100 << ", going ";
         if(highwayNumber % 2 == 0) 
            cout << "east/west." << endl;
         else 
            cout << "north/south." << endl;
      }
   }
   return 0;
}
