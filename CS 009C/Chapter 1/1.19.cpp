#include <iostream>
#include <iomanip>
using namespace std;

int main() {

   int count = 0; 
   int sum = 0; 
   int num = 0;
   int max = 0;
   
   cin >> num;
   while(num >= 0) {
      sum += num;
      count++;
      if(num > max) 
         max = num;
      cin >> num;
      
   }
   
   cout << fixed << setprecision(2) << max << " " << static_cast<double>(sum)/static_cast<double>(count) << endl;


   return 0;
}
