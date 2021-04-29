#include <cstring>

#include "Array.hpp"

void int_array_tests()
{
	std::cout << "INT\n" << std::endl;
	Array<int> empty_array;
	std::cout << "empty_array size : " << empty_array.size() << std::endl;

	Array<int> int_array(4);
	std::cout << "\narray of 4 elements :" << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << std::endl;
	}

	std::cout << "\nassigning values..." << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		int_array[i] = i + 1;
		std::cout << int_array[i] << std::endl;
	}
	std::cout << "\ncopy constructor and assignement operator :" << std::endl;
	Array<int> other_int_array(int_array);
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << std::endl;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < other_int_array.size(); i++) {
		std::cout << other_int_array[i] << std::endl;
	}
	std::cout << "\nmodifying copy" << std::endl;
	for (std::size_t i = 0; i < other_int_array.size(); i++) {
		other_int_array[i] = -(i + 1);
		std::cout << other_int_array[i] << std::endl;
	}
	std::cout << "\ncheck if first array is unchanged" << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << std::endl;
	}

	std::cout << "\nout of limits indexes tests" << std::endl;
	try {
		std::cout << "-1 index" << std::endl;
		std::cout << int_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "4 index (array size)" << std::endl;
		std::cout << int_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "9999 index" << std::endl;
		std::cout << int_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
}

void float_array_tests()
{
	std::cout << "FLOAT\n" << std::endl;
	Array<float> empty_array;
	std::cout << "empty_array size : " << empty_array.size() << std::endl;

	Array<float> float_array(4);
	std::cout << "\narray of 4 elements :" << std::endl;
	for (std::size_t i = 0; i < float_array.size(); i++) {
		std::cout << float_array[i] << std::endl;
	}

	std::cout << "\nassigning values..." << std::endl;
	for (std::size_t i = 0; i < float_array.size(); i++) {
		float_array[i] = i + 1.42;
		std::cout << float_array[i] << std::endl;
	}
	std::cout << "\ncopy constructor and assignement operator :" << std::endl;
	Array<float> other_float_array(float_array);
	for (std::size_t i = 0; i < float_array.size(); i++) {
		std::cout << float_array[i] << std::endl;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < other_float_array.size(); i++) {
		std::cout << other_float_array[i] << std::endl;
	}
	std::cout << "\nmodifying copy" << std::endl;
	for (std::size_t i = 0; i < other_float_array.size(); i++) {
		other_float_array[i] = -(i + 1.42);
		std::cout << other_float_array[i] << std::endl;
	}
	std::cout << "\ncheck if first array is unchanged" << std::endl;
	for (std::size_t i = 0; i < float_array.size(); i++) {
		std::cout << float_array[i] << std::endl;
	}

	std::cout << "\nout of limits indexes tests" << std::endl;
	try {
		std::cout << "-1 index" << std::endl;
		std::cout << float_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "4 index (array size)" << std::endl;
		std::cout << float_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "9999 index" << std::endl;
		std::cout << float_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
}

void int_ptr_array_tests()
{
	int ints[4] = { 1, 2, 3, 4};
	int other_ints[4] = { -1, -2, -3, -4};

	std::cout << "INT POINTER\n" << std::endl;
	Array<int*> empty_array;
	std::cout << "empty_array size : " << empty_array.size() << std::endl;

	Array<int*> int_array(4);
	std::cout << "\narray of 4 elements :" << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << " alias NULL" << std::endl;
	}

	std::cout << "\nassigning values..." << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		int_array[i] = ints + i;
		std::cout << int_array[i] << " : " << *int_array[i] << std::endl;
	}
	std::cout << "\ncopy constructor and assignement operator :" << std::endl;
	Array<int*> other_int_array(int_array);
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << " : " << *int_array[i] << std::endl;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < other_int_array.size(); i++) {
		std::cout << other_int_array[i] << " : " << *other_int_array[i] << std::endl;
	}
	std::cout << "\nmodifying copy..." << std::endl;
	for (std::size_t i = 0; i < other_int_array.size(); i++) {
		other_int_array[i] = other_ints + i;
		std::cout << other_int_array[i] << " : " << *other_int_array[i] << std::endl;
	}
	std::cout << "\ncheck if first array is unchanged" << std::endl;
	for (std::size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << " : " << *int_array[i] << std::endl;
	}

	std::cout << "\nout of limits indexes tests" << std::endl;
	try {
		std::cout << "-1 index" << std::endl;
		std::cout << int_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "4 index (array size)" << std::endl;
		std::cout << int_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "9999 index" << std::endl;
		std::cout << int_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
}

void string_array_tests()
{
	std::string strings[4] = { "Hel", "lo ", "wor", "ld!"};
	std::string other_strings[4] = { "foo", "bar", "FOO", "BAR"};
	std::cout << "STRING\n" << std::endl;
	Array<std::string> empty_array;
	std::cout << "empty_array size : " << empty_array.size() << std::endl;

	Array<std::string> string_array(4);
	std::cout << "\narray of 4 elements :" << std::endl;
	for (std::size_t i = 0; i < string_array.size(); i++) {
		std::cout << string_array[i] << std::endl;
	}

	std::cout << "\nassigning values..." << std::endl;
	for (std::size_t i = 0; i < string_array.size(); i++) {
		string_array[i] = strings[i];
		std::cout << string_array[i] << std::endl;
	}
	std::cout << "\ncopy constructor and assignement operator :" << std::endl;
	Array<std::string> other_string_array(string_array);
	for (std::size_t i = 0; i < string_array.size(); i++) {
		std::cout << string_array[i] << std::endl;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < other_string_array.size(); i++) {
		std::cout << other_string_array[i] << std::endl;
	}
	std::cout << "\nmodifying copy" << std::endl;
	for (std::size_t i = 0; i < other_string_array.size(); i++) {
		other_string_array[i] = other_strings[i];
		std::cout << other_string_array[i] << std::endl;
	}
	std::cout << "\ncheck if first array is unchanged" << std::endl;
	for (std::size_t i = 0; i < string_array.size(); i++) {
		std::cout << string_array[i] << std::endl;
	}

	std::cout << "\nout of limits indexes tests" << std::endl;
	try {
		std::cout << "-1 index" << std::endl;
		std::cout << string_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "4 index (array size)" << std::endl;
		std::cout << string_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try {
		std::cout << "9999 index" << std::endl;
		std::cout << string_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
}

int main()
{
	int_array_tests();
	std::cout << std::endl;
	float_array_tests();
	std::cout << std::endl;
	int_ptr_array_tests();
	std::cout << std::endl;
	string_array_tests();
}
