#include <algorithm>
#include <iostream>

template <typename T>
void List<T>::insert(T const& d)
{
  	first = new Link(d, first);
}

// Important copy and assignment stuff
template <typename T>
typename List<T>::Link* List<T>::Link::clone(Link const* dolly)
{
  	if ( dolly != nullptr )
    	return new Link(dolly->data, clone(dolly->next));
  	else
    	return nullptr;
}

template <typename T>
List<T>::List() : first(nullptr)
{
  	std::clog << "***Default construction" << std::endl;
}

template <typename T>
List<T>::List(List const& l)
{
  	std::clog << "***Copy construction" << std::endl;
  	first = Link::clone(l.first);
}

template <typename T>
List<T>::List(List&& l)
{
  	std::clog << "***Move construction" << std::endl;
  	first = l.first;
  	l.first = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(List<T> const& rhs)
{
  	std::clog << "***Copy assignment" << std::endl;
  	if (&rhs != this)
  	{
    	List<T> copy(rhs);
    	std::swap(first, copy.first);
 	}
  	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
  	std::clog << "***Move assignment" << std::endl;
  	if (&rhs != this)
  	{
    	std::swap(first, rhs.first);
  	}
  	return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
  	return List<T>::Iterator{first};
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
  	return List<T>::Iterator{nullptr};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list)
{
  	for (auto& i : list)
  	{
    	os << i << " ";
  	}
  	os << std::endl;
  return os;
}

template <typename T>
List<T>::Iterator::Iterator(List<T>::Link* link)
	: current{link} {}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
  	current = current->next;
  	return *this; 
}

template <typename T>
bool List<T>::Iterator::operator!=(Iterator const& other)
{
  	return current != other.current; 
}

template <typename T>
T& List<T>::Iterator::operator*()
{
  	return current->data; 
}
