#include <iostream>
#include "whatever.hpp"

int first = 12345;
int second = 42;

int* first_ptr = &first;
int* second_ptr = &second;

float ffirst = 12345.12345;
float fsecond = 42.42;

Point Pfirst (12345.12345, 54321.54321);
Point Psecond (21.21, 42.42);

void swap_tests()
{
	std::cout << "SWAP TESTS" << std::endl;

	std::cout << "\nINT\n" << std::endl;
	std::cout << "first : " << first << "\tsecond: " << second << std::endl;
	swap(first, second);
	std::cout << "first : " << first << "\tsecond: " << second << std::endl;
	swap<int>(first, second);
	std::cout << "first : " << first << "\tsecond: " << second << std::endl;

	std::cout << "\nINT POINTER\n" << std::endl;
	std::cout << "first_ptr : " << first_ptr << "\tsecond_ptr: " << second_ptr << std::endl;
	std::cout << "*first_ptr : " << *first_ptr << "\t*second_ptr: " << *second_ptr << std::endl;
	swap(first_ptr, second_ptr);
	std::cout << "first_ptr : " << first_ptr << "\tsecond_ptr: " << second_ptr << std::endl;
	std::cout << "*first_ptr : " << *first_ptr << "\t*second_ptr: " << *second_ptr << std::endl;
	swap<int*>(first_ptr, second_ptr);
	std::cout << "first_ptr : " << first_ptr << "\tsecond_ptr: " << second_ptr << std::endl;
	std::cout << "*first_ptr : " << *first_ptr << "\t*second_ptr: " << *second_ptr << std::endl;

	std::cout << "\nFLOAT\n" << std::fixed << std::endl;
	std::cout << "ffirst : " << ffirst << "\tfsecond: " << fsecond << std::endl;
	swap(ffirst, fsecond);
	std::cout << "ffirst : " << ffirst << "\tfsecond: " << fsecond << std::endl;
	swap<float>(ffirst, fsecond);
	std::cout << "ffirst : " << ffirst << "\tfsecond: " << fsecond << std::endl;

	std::cout << "\nPOINT object\n" << std::endl;
	std::cout << "Pfirst : " << Pfirst << "\tPsecond: " << Psecond << std::endl;
	swap(Pfirst, Psecond);
	std::cout << "Pfirst : " << Pfirst << "\tPsecond: " << Psecond << std::endl;
	swap<Point>(Pfirst, Psecond);
	std::cout << "Pfirst : " << Pfirst << "\tPsecond: " << Psecond << std::endl;
	return;
}

void min_tests()
{
	std::cout << "MIN TESTS" << std::endl;

	std::cout << "\nINT" << std::endl;
	std::cout << "first : " << first << "\tsecond: " << second << std::endl;
	std::cout << "\tmin: " << min(first, second) << std::endl;
	std::cout << "\tmin: " << min<int>(first, second) << std::endl;

	std::cout << "\nFLOAT" << std::fixed << std::endl;
	std::cout << "ffirst : " << ffirst << "\tfsecond: " << fsecond << std::endl;
	std::cout << "\tfmin: " << min(ffirst, fsecond) << std::endl;
	std::cout << "\tfmin: " << min<float>(ffirst, fsecond) << std::endl;

	std::cout << "\nPOINT object" << std::endl;
	std::cout << "Pfirst : " << Pfirst << "\tPsecond: " << Psecond << std::endl;
	std::cout << "\tPmin: " << min(Pfirst, Psecond) << std::endl;
	std::cout << "\tPmin: " << min<Point>(Pfirst, Psecond) << std::endl;
	return;
}

void max_tests()
{
	std::cout << "MAX TESTS" << std::endl;

	std::cout << "\nINT" << std::endl;
	std::cout << "first : " << first << "\tsecond: " << second << std::endl;
	std::cout << "\tmax: " << max(first, second) << std::endl;
	std::cout << "\tmax: " << max<int>(first, second) << std::endl;

	std::cout << "\nFLOAT" << std::fixed << std::endl;
	std::cout << "ffirst : " << ffirst << "\tfsecond: " << fsecond << std::endl;
	std::cout << "\tfmax: " << max(ffirst, fsecond) << std::endl;
	std::cout << "\tfmax: " << max<float>(ffirst, fsecond) << std::endl;

	std::cout << "\nPOINT object" << std::endl;
	std::cout << "Pfirst : " << Pfirst << "\tPsecond: " << Psecond << std::endl;
	std::cout << "\tPmax: " << max(Pfirst, Psecond) << std::endl;
	std::cout << "\tPmax: " << max<Point>(Pfirst, Psecond) << std::endl;
	return;
}

int main()
{
	swap_tests();
	std::cout << "\n" << std::endl;
	min_tests();
	std::cout << "\n" << std::endl;
	max_tests();
	return 0;
}

/*
int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
*/
