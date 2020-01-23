#include "FileReader.h"
#include <locale>
using namespace std;



void FileReader::eraser(string myFile)
{
	myFile.erase(0, myFile.find_first_not_of("\"\'("));
	myFile.erase(myFile.find_last_not_of(",;.:?!\"\')") + 1);
	if (0 == myFile.compare(myFile.size() - 2, 2, "\'s"))
		myFile.erase(myFile.size() - 2);
	if (myFile.size() < 3) return;
	transform(myFile.begin(), myFile.end(), myFile.begin(), ::tolower);
	findValidWord(myFile);
}

void FileReader::findValidWord(string const myFile)
{
		bool isValidWord = false;
			auto iterateWord = [&isValidWord](char c) mutable {
			if (!isalpha(c) && c != '-') {
				isValidWord = true;
			}
		};
		for_each(myFile.begin(), myFile.end(), iterateWord);

	if (isValidWord) return;
	if (myFile.at(0) == '-' || myFile.at(myFile.size() - 1) == '-' || myFile.find("--") != string::npos) return;
	wordlist.push_back(myFile);
}

void FileReader::sorting() {

	if (secondArg != "-o") {
		sort(wordlist.begin(), wordlist.end());
		}

auto func = [&](string c){prepareWords(c); };
std::for_each(wordlist.begin(), wordlist.end(), func);

	func("[");

	if (secondArg == "-f") {
		sort(wordkopies.begin(), wordkopies.end(), sortbyCopies());
	}
	
}


void FileReader::prepareWords(string const word){
	if (secondArg != "-o") {
		if (lastWord == "") {
			lastWord == word;
		}
		else if (lastWord != word) {

			fWordlist fWord{ lastWord, copies };
			wordkopies.push_back(fWord);
			copies = 1;

		}
		else {
			copies++;
		}
		lastWord = word;
	}
	else {
		
	if (word == "[" || words.length() + word.length() >= thirdArg) {
		cout << words << "\n";
		words = word + " ";
	}
	else {
		words = words + word + " ";
	}
	}
}


void FileReader::print() const
{

auto func = [&](fWordlist const word){printWords(word); };
std::for_each(wordkopies.begin(), wordkopies.end(), func);

}



void FileReader::printWords(fWordlist const word) const {
	auto test = *std::max_element(wordlist.begin(),wordlist.end());
	cout.width(test.length());
	if (secondArg == "-a") {
		cout << std::left << word.word;
	}
	else {
		cout << word.word;
	}
	cout << " " << word.copies << endl;
}

