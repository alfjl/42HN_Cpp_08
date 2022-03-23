#include <iostream>
#include <climits>
#include "Span.hpp"

int main()
{
	std::cout << " ##### STANDARD 42 TEST ##### " << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n ##### TEST LAST ELEMENT ##### " << std::endl;
	Span sp2 = Span(5);

	sp2.addNumber(6);
	sp2.addNumber(2);
	sp2.addNumber(17);
	sp2.addNumber(16);
	sp2.addNumber(11);

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "\n ##### TEST NEGATIVE NUMBER ##### " << std::endl;
	Span sp3 = Span(5);

	sp3.addNumber(6);
	sp3.addNumber(3);
	sp3.addNumber(17);
	sp3.addNumber(-9);
	sp3.addNumber(11);

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	
	std::cout << "\n ##### TEST ALL NEGATIVE ##### " << std::endl;
	Span sp4 = Span(5);

	sp4.addNumber(-6);
	sp4.addNumber(-3);
	sp4.addNumber(-100);
	sp4.addNumber(-16);
	sp4.addNumber(-1);

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;


	std::cout << "\n ##### TEST MAX & MIN INT ##### " << std::endl;
	Span sp5 = Span(5);

	sp5.addNumber(6);
	sp5.addNumber(6);
	sp5.addNumber(INT_MAX);
	sp5.addNumber(16);
	sp5.addNumber(INT_MIN);
	
	std::cout << sp5.shortestSpan() << std::endl;
	std::cout << sp5.longestSpan() << std::endl;

	std::cout << "\n ##### TEST TOO MANY ENTRIES EXEPTION ##### " << std::endl;
	try
	{
		Span sp6 = Span(2);

		sp6.addNumber(6);
		sp6.addNumber(3);
		sp6.addNumber(17);

		std::cout << sp6.shortestSpan() << std::endl;
		std::cout << sp6.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ##### TEST NOT ENOUGH ENTRIES EXEPTION ##### " << std::endl;
	
	try
	{	
		Span sp7 = Span(1);

		sp7.addNumber(6);

		std::cout << sp7.shortestSpan() << std::endl;
		std::cout << sp7.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ##### TEST NOT ENOUGH ENTRIES EXEPTION - Span(0) ##### " << std::endl;
	
	try
	{	
		Span sp8 = Span(0);

		std::cout << sp8.shortestSpan() << std::endl;
		std::cout << sp8.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ##### TEST ITERATOR & 15000 NUMBERS ##### " << std::endl;
	Span				sp8 = Span(15000);
	std::vector<int>	testVector;

	for (int i = 0; i < 15000; i++)
		testVector.push_back(i);
	
	try
	{
		sp8.addNumber(testVector.begin(), testVector.end());
		std::cout << sp8.shortestSpan() << std::endl;
		std::cout << sp8.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "\n ##### EXCEPTION: TEST ITERATOR & 15000 NUMBERS ##### " << std::endl;
	Span				sp9 = Span(12000);
	
	try
	{
		sp9.addNumber(testVector.begin(), testVector.end());
		std::cout << sp9.shortestSpan() << std::endl;
		std::cout << sp9.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	return 0;
}
