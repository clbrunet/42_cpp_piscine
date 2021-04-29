#include "easyfind.hpp"

void list_test()
{
	std::cout << "LIST" << std::endl;
	std::list<int> lst;
	for (int i = 1; i < 6; i++) {
		lst.push_back(i);
	}
	for (std::list<int>::const_iterator it = lst.begin(), end = lst.end();
			it != end; it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << *easyfind<std::list<int> >(lst, 1) << std::endl;
		std::cout << *easyfind<std::list<int> >(lst, 2) << std::endl;
		std::cout << *easyfind<std::list<int> >(lst, 3) << std::endl;
		std::cout << *easyfind<std::list<int> >(lst, 4) << std::endl;
		std::cout << *easyfind<std::list<int> >(lst, 5) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	try {
		std::cout << *easyfind<std::list<int> >(lst, 0) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind<std::list<int> >(lst, 6) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind<std::list<int> >(lst, 9999) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void vector_test()
{
	std::cout << "VECTOR" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i < 6; i++) {
		vec.push_back(i);
	}
	for (std::vector<int>::const_iterator it = vec.begin(), end = vec.end();
			it != end; it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << *easyfind<std::vector<int> >(vec, 1) << std::endl;
		std::cout << *easyfind<std::vector<int> >(vec, 2) << std::endl;
		std::cout << *easyfind<std::vector<int> >(vec, 3) << std::endl;
		std::cout << *easyfind<std::vector<int> >(vec, 4) << std::endl;
		std::cout << *easyfind<std::vector<int> >(vec, 5) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	try {
		std::cout << *easyfind<std::vector<int> >(vec, 0) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind<std::vector<int> >(vec, 6) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind<std::vector<int> >(vec, 9999) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	list_test();
	std::cout << std::endl;
	vector_test();
	return 0;
}
