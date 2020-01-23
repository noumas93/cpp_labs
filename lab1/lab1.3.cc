#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main () {

  ifstream inFile{};

inFile.open("text.txt");

if (!inFile) {

  cerr << "Unable to open file text.txt " << endl;
  exit(1);
 }

 ifstream ifs{"text.txt"};
 string s{};
 int wordCount {};
 string shortestWord{};
 string longestWord{};
 int shortest_Wordlength {};
 int longest_Wordlength {};
 int allWordsLength{};
 while (ifs >> s) {

   allWordsLength += s.length();
   wordCount ++;
   
   if (shortest_Wordlength <= 0 && s.length() > 0) {
     shortest_Wordlength = s.length();
     shortestWord = s;
   }
   if ((int)s.length() < shortest_Wordlength) {
     shortest_Wordlength = s.length();
     shortestWord = s;
   }
   if ((int)s.length() > longest_Wordlength) {
     longest_Wordlength = s.length();
     longestWord = s;
   }

   
 }

 inFile.close();
 double wordLengthAvg{};
 wordLengthAvg = (double)allWordsLength/(double)wordCount;
 cout << "\n" << "there are " <<  wordCount << " words in the file." << endl;
 cout << "The shortest word was \"" << shortestWord << "\" with ";
 cout << shortest_Wordlength << " character(s)." << endl;
 cout << "The longest word was \"" << longestWord << "\" with ";
 cout << longest_Wordlength << " character(s)." << endl;
 cout << fixed << setprecision(2);
 cout << "The average length was " << wordLengthAvg;
 cout << " character(s)." << "\n" << endl;

 return 0;
}
