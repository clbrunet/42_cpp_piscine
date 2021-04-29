#include "mutantstack.hpp"
#include <list>

void mstack_test()
{
	std::cout << "MutantStack" << std::endl;
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

	std::cout << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << mstack.top() << std::endl;
	std::cout << s.top() << std::endl;
}

void list_test()
{
	std::cout << "list" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(list);

	std::cout << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << s.back() << std::endl;
	s.pop_back();
	std::cout << list.back() << std::endl;
	std::cout << s.back() << std::endl;
}

void other_tests()
{
	std::cout << "Other tests" << std::endl;
	MutantStack<double> mstack;
	std::cout << std::boolalpha << "empty : " << mstack.empty() << std::endl;
	MutantStack<double>::iterator it = mstack.begin();
	MutantStack<double>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	mstack.push(42.42);
	std::cout << std::boolalpha << "empty : " << mstack.empty() << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	it = mstack.begin();
	mstack.push(12345.54321);
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	mstack_test();
	std::cout << std::endl;
	list_test();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	other_tests();
	return 0;
}
