#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
  
  int integer{};
  char myChar{};
  string str{};
  double doub{};


  cout << "enter one integer: ";
  cin >> integer;
  cout << "You entereed the number: " << integer << endl;
  cin.ignore(1000, '\n');
  cout << "enter four integers: ";
  cin >> integer;
  cout << "you entered the numbers: "<< integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << endl;
  cin.ignore(1000, '\n');



 cout << "enter one integer and one real number ";
 cin >> integer >> doub;
  cout <<  "the real is: ";
  cout << fixed << setprecision(3) << setw(11) << doub << endl ;
  cout << "the integer is: ";
  cout << setw(8) << integer << endl;
cin.ignore(1000, '\n');

  cout << "Enter one real and one integer number: ";
  cin >> doub; cin >> integer;

  cout <<  "the real is: ";
  cout << setfill('.') << setw(11) << doub << endl;

  cout << "the integer is: ";
  cout << setw(8) << integer << endl;
  cin.ignore(1000, '\n');

  cout << "Enter a character: ";
  cin  >> myChar;

  cout << "You entered: " << myChar << endl;
  cin.ignore( 1000 , '\n');

  cout << "Enter a word: ";
  cin >> str;

  cout << "The word '"<< str << "' has " << str.length() << " character(s)!\n";

  cout << "Enter an integer and a word: ";
  cin >> integer >> str;
  cout << "You entered '" << integer << "' and '" << str << "'." << endl;
  cin.ignore( 1000 , '\n');

  cout << "Enter a character and a word: ";
  cin >> myChar >> str;
  cout << "You entered the string \"" << str << "\" and the character '" << myChar << "'." << endl;
  cin.ignore( 1000 , '\n');

 
  cout << "Enter a word and a real number: ";
  cin >> str >> doub;
  cout << fixed << setprecision(3) << "You entered \"" << str << "\" and \"" << doub << "\"." << endl;
  cin.ignore( 1000 , '\n');



  cout << "Enter a text-line: ";
  getline(cin, str);

  cout << "You entered: " << str << endl;
  cout << "Enter a second line of text: ";
  getline(cin, str);
  cout << "You entered: '" << str << "\"" << endl;

  cout << "Enter three words: ";

 cin >> str;
 cout << "You entered: '"<< str << " ";
 cin >> str;
 cout << str << " ";
 cin >> str;
 cout << str << "'" << endl;

  return 0;
}
