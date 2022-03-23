#pragma once

#include <vector>
#include <exception>

class	Span
{
private:
	unsigned int		_maxSize;
	unsigned int		_currentSize;
	std::vector<int>	_internalVector;

	Span( void );

public:
	Span( unsigned int N );
	Span( const Span &other );
	~Span( void );

	Span		&operator=( const Span &src );

	void		addNumber( int number );
	//void	addRangeOfNumbers(unsigned int how_many_numbers, int range_from, int range_to);
	long long	shortestSpan( void );
	long long	longestSpan( void );

	class	TooManyEntriesException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

	class	NotEnoughEntriesException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};
};
