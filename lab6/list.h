#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

template <typename T>
class List;

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list);

template <typename T>
class List
{
public:
  	List();
  	~List() { delete first; }

  	void insert(T const& d);
  
  	List(List const&);
  	List(List&&);
  	List& operator=(List const&);
  	List& operator=(List&&);

  	friend std::ostream& operator<< <> (std::ostream& os, List<T>& list);
  	class Iterator;
  	Iterator begin();
  	Iterator end();
private:

  	class Link
 	{
  	public:
    	Link(T const& d, Link* n)
      		: data(d), next(n) {}
    	~Link() { delete next; }
    
    	friend class List;

    	static Link* clone(Link const*);
    
  	private:
    	T data;
    	Link* next;
  	};
  
  	Link* first;
  
public:

  	using value_type = T;

  	class Iterator
  	{
    public:      
      	friend class List;

      	Iterator& operator++();
      	bool operator!=(Iterator const& other);
      	T& operator*();

    private:
      	Iterator(Link* link);
      	Link* current;
  	};
};

  	#include "list.tcc"

#endif
