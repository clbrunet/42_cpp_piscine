#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() :
		std::stack<T>()
	{
		return;
	}
	MutantStack(MutantStack const& src) :
		std::stack<T>(src)
	{
		return;
	}
	~MutantStack()
	{
		return;
	}

	typedef typename std::deque<T>::iterator iterator;
 	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}

private:

	MutantStack& operator=(MutantStack const& rhs)
	{
		static_cast<void>(rhs);
		return *this;
	}
};

#endif
