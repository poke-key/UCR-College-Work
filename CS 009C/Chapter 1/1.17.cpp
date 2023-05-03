#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  int age;
  int weight;
  int heart_rate;
  int minutes;
  double calories;
  
  cin >> age;
  cin >> weight;
  cin >> heart_rate;
  cin >> minutes;
  
  calories = ((age * 0.2757) + (weight * 0.03295) + (heart_rate * 1.0781) - 75.4991 ) * minutes / 8.368;
  
  cout << "Calories: " << fixed << setprecision(2) << calories << " calories" << endl;
  

   return 0;
}
