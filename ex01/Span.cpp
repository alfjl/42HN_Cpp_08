#include <algorithm>
#include <vector>
#include <climits>
#include "Span.hpp"

Span::Span( void ) : _maxSize(0), _currentSize(0)
{}

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0)
{}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span( void )
{}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_maxSize = src._maxSize;
		this->_currentSize = src._currentSize;
		this->_internalVector = src._internalVector;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_currentSize == this->_maxSize)
		throw Span::TooManyEntriesException();
	this->_internalVector.push_back(number);
	this->_currentSize++;
}

//void	Span::addRangeOfNumbers(unsigned int how_many_numbers, int range_from, int range_to)
//{
	//
//}

long long	Span::shortestSpan( void )
{
	long long	shortSpan = LLONG_MAX;

	if (this->_currentSize < 2)
		throw Span::NotEnoughEntriesException();

	std::vector<int>	copy = this->_internalVector;
	std::sort(copy.begin(), copy.end());

	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	{
		if ((it + 1) != copy.end())
		{
			if ( static_cast<long long>( *(it + 1) ) - static_cast<long long>( *it ) < shortSpan )
				shortSpan =  static_cast<long long>( *(it + 1) ) - static_cast<long long>( *it );
		}
	}

	return (shortSpan);
}

long long	Span::longestSpan( void )
{
	if (this->_currentSize < 2)
		throw Span::NotEnoughEntriesException();
	
	std::vector<int>	copy = this->_internalVector;
	std::sort(copy.begin(), copy.end());
	
	return ( static_cast<long long>(std::max(*copy.begin(), *(copy.end() - 1))) - static_cast<long long>(std::min(*copy.begin(), *(copy.end() - 1))) );
}

const char	*Span::TooManyEntriesException::what() const throw()
{
	return ("Error: internal array not big enough");
}

const char	*Span::NotEnoughEntriesException::what() const throw()
{
	return ("Error: not enough entries");
}
