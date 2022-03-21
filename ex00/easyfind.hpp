#pragma once

#include <algorithm>
#include <iterator>
#include <exception>

class	NotFoundException : public std::exception
{
public:
	virtual	const char	*what() const throw();
};

const char	*NotFoundException::what() const throw()
{
	return ("Error: Value not found");
}

template< typename T >
typename T::iterator	easyfind( T &container, int value )
{
	typename T::iterator	foundElement;

	foundElement = std::find(container.begin(), container.end(), value);
	if (foundElement == container.end())
		throw NotFoundException();
	return (foundElement);
}
