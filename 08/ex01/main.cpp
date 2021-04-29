#include "span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(5);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }

int main()
{
	std::srand(time(NULL));
	Span sp = Span(5);

	try {
		std::cout << sp.shortestSpan() << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}

	sp.addNumber(5);

	try {
		std::cout << sp.shortestSpan() << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	try {
		sp.addNumber(30);
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span small_sp = Span(10);
	small_sp.generate();
	std::cout << small_sp.shortestSpan() << std::endl;
	std::cout << small_sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span medium_sp = Span(500);
	medium_sp.generate();
	std::cout << medium_sp.shortestSpan() << std::endl;
	std::cout << medium_sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span large_sp = Span(1000);
	large_sp.generate();
	std::cout << large_sp.shortestSpan() << std::endl;
	std::cout << large_sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span extra_large_sp = Span(10000);
	extra_large_sp.generate();
	std::cout << extra_large_sp.shortestSpan() << std::endl;
	std::cout << extra_large_sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span extra_extra_large_sp = Span(50000);
	extra_extra_large_sp.generate();
	std::cout << extra_extra_large_sp.shortestSpan() << std::endl;
	std::cout << extra_extra_large_sp.longestSpan() << std::endl;
	std::cout << std::endl;

	try {
		extra_extra_large_sp.addNumber(42);
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception message : " << e.what() << std::endl;
	}
}
