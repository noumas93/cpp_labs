#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {


  cout << "INPUT PART" << endl;

  cout << fixed << setfill('=')  << setw(10) << "\n";

    float firstPrice  {-1} ;
  while (firstPrice < 0) {
    cout << "Enter first price: ";
    cin >> firstPrice;
    if (firstPrice < 0) {
      cerr << "Error: First price must be at least 0 (zero) sek." << endl;
    }
  };

    float lastPrice {-2};
  while (lastPrice <= firstPrice) {
    cout << "Enter last price : "; 
    cin >> lastPrice;
    if (lastPrice <= firstPrice ) {
      cerr << "Last price must be larger than first price." << endl;
    }
  };
    float stride  {0};
  while (stride < 0.01) {
    cout << "Enter stride" << setfill(' ') << setw(7) << ": "; 
    cin >> stride;
    if (stride  <  0.01) {
      cerr << "ERROR: Stride must be at least 0.01" << endl;
    };
  };
    float taxPercent {-1};
  while (taxPercent < 0 || taxPercent > 100) {
    cout << "Enter tax percent: "; 
    cin >> taxPercent;
    if (taxPercent < 0 || taxPercent > 100) {
      cerr << "ERROR: tax percent must be larger than 0 and smaller then 100!" << endl;
    };
  };


  cout << "TAX TABLE" << endl;
  cout << setfill('=')  << setw(10) << "\n";
  cout << setfill(' ') <<setw(12) << "Price";
  cout << setw(17) << "Tax " << setw(21) << "price with tax" << endl;
  cout << setfill('-') << setw(50) << "\n";
  
  for (float i=firstPrice; i<=lastPrice; i = i + stride ) {
    cout << setfill(' ') << setprecision (2) << setw(12) << firstPrice;
    cout << setw(17) << firstPrice*taxPercent/100;
    cout << setw(21) << firstPrice*taxPercent/100 + firstPrice << endl;
    firstPrice = firstPrice  + stride;


  }







  return 0;
}
