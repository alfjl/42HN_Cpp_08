#pragma once

#include <stack>

template< typename T >
class	MutantStack : public std::stack< T >
{
public:

	typedef typename std::stack<T>::container_type::iterator	iterator;

	MutantStack() {}
	MutantStack(const MutantStack &other) { *this = other; }
	~MutantStack() {}

	MutantStack	&operator=(const MutantStack &src)
	{
		if (this != &src)
			std::stack<T>::container_type.c = src.c;
		return (*this);
	}

	iterator	begin( void )
	{
		return (this->c.begin());
	}
	
	iterator	end( void )
	{
		return (this->c.end());
	}
};
