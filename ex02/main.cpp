#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << " ##### MUTANT STACK INT ##### " << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);



	std::cout << " ##### STD::LIST INT ##### " << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << *(mlist.rbegin()) << std::endl;

	mlist.pop_back();

	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);

	mlist.push_back(0);

	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator ite2 = mlist.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> l(mlist);



	std::cout << " ##### MUTANT STACK STD::STRING ##### " << std::endl;
	MutantStack<std::string> mstrstack;

	mstrstack.push("five");
	mstrstack.push("seventeen");

	std::cout << mstrstack.top() << std::endl;

	mstrstack.pop();

	std::cout << mstrstack.size() << std::endl;

	mstrstack.push("three");
	mstrstack.push("five");
	mstrstack.push("sevenhundredthirtyseven");

	mstrstack.push("zero");

	MutantStack<std::string>::iterator itstr = mstrstack.begin();
	MutantStack<std::string>::iterator itestr = mstrstack.end();

	++itstr;
	--itstr;
	while (itstr != itestr)
	{
		std::cout << *itstr << std::endl;
		++itstr;
	}
	std::stack<std::string> str(mstrstack);


	return 0;
}
