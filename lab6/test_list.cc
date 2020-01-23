#include <iostream>
#include "list.h"

using namespace std;

#define SOLUTION 1 // Change to 1 when completely done

int main()
{
#if SOLUTION == 0

#else

  	{
    	List<int> list;
    	decltype(list)::value_type number;
		//The list is filled with data here...
		//...
    	cout << "Enter some numbers. End with Ctrl+D" << endl;  
    	while (cin >> number)
    	{
      		list.insert(number);
    	}
		cout << endl;
    	for ( decltype(list)::Iterator it{ list.begin() }; it != list.end(); ++it)
    	{
      		cout << *it << " ";
    	}
    	cout << endl;
		
    	for ( auto s : list )
    	{
      		cout << s << " ";
    	}
    	cout << endl;

    	cout << list << endl;
  	}

  	cin.clear();

  	{
    	List<std::string> list;
    	decltype(list)::value_type word;
    
    	cout << "Enter some words. Finish with Ctrl+D " << endl;  
    	while (cin >> word)
    	{
      		list.insert(word);
    	}
		cout << endl;
    	for ( decltype(list)::Iterator it{ list.begin() }; it != list.end(); ++it)
    	{
      		cout << *it << " ";
    	}
    	cout << endl;
    
    	for ( auto s : list )
    	{
      		cout << s << " ";
    	}
    	cout << endl;
    
    	cout << list << endl;
  	}
#endif

  	return 0;
}
