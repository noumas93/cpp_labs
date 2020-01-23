#include <cstdio>
#include <string>
#include <iostream>
#include "FileReader.h"

using namespace std;


int main(int argc, char** argv)
{
	
	string arg1;
	string arg2;
	try
	{
	arg1 = argv[1];
	arg2 = argv[2];
	}
	catch (...)
	{
		if (!argv[1]) {
			cout << "Error: No arguments given." << endl;
			cout << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
		}
		if (!argv[2]) {
			cout << "Error: Second argument missing or invalid." << endl;
			cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
		}
	}

		if((string(argv[2]) == "-o") && argc < 4){
				cout << "Error: third argument missing or invalid." << endl;
				return 0;

		}
		else {

int arg3 = 0;
 if (string(argv[2]) == "-o") {
			arg3 = stoi(argv[3]);
			
		}

		FileReader fileReader{arg1, arg2, arg3};
		
		ifstream fileInput{arg1};
		istream_iterator<string> first(fileInput);
		istream_iterator<string> end;
		list<string> words;
		copy(first, end, back_inserter(words));

		auto eraser = [&fileReader](string fileWord){ fileReader.eraser(fileWord); };
		for_each(words.begin(), words.end(), eraser);

		fileReader.sorting();
		if (arg2 == "-a" || arg2 == "-f") {
			fileReader.print();
		}

		}


	return 0;

}
