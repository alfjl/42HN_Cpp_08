#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "easyfind.hpp"

int	main( void )
{
	std::vector<int>	testVector;
	std::list<int>		testList;


	for (int i = 0; i < 100; i++)
		testVector.push_back(i);

	for (int i = 0; i < 100; i++)
		testList.push_back(i);


	std::cout << "##### VECTOR FOUND #####" << std::endl;
	try
	{
		std::vector<int>::iterator	returnPointer = easyfind(testVector, 99);
		std::cout << "found int " << *returnPointer << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "##### VECTOR NOT FOUND #####" << std::endl;
	try
	{
		std::vector<int>::iterator	returnPointer = easyfind(testVector, 100);
		std::cout << "found int " << *returnPointer << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "##### LIST FOUND #####" << std::endl;
	try
	{
		std::list<int>::iterator	returnPointer = easyfind(testList, 99);
		std::cout << "found int " << *returnPointer << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "##### LIST NOT FOUND #####" << std::endl;
	try
	{
		std::list<int>::iterator	returnPointer = easyfind(testList, 100);
		std::cout << "found int " << *returnPointer << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}
