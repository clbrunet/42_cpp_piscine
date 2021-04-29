#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <list>
#include <vector>

// template <typename T>
// typename T::const_iterator easyfind(T const& int_container, int const val)
// {
// 	return std::find(int_container.begin(), int_container.end(), val);
// }

class ValueNotFoundException : public std::exception
{
public:
	virtual char const* what() const throw()
	{
		return "value not found in container";
	}
};

template <typename T>
typename T::const_iterator easyfind(T const& int_container, int const val)
{
	typename T::const_iterator cit = std::find(int_container.begin(),
			int_container.end(), val);
	if (cit == int_container.end()) {
		throw ValueNotFoundException();
	}
	return cit;
}

#endif
