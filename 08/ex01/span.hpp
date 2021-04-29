#ifndef SPAN_HPP
#define SPAN_HPP

#include <climits>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
public:
	class ExceedMaxNumbersException : public std::exception
	{
		virtual char const* what() const throw();
	};
	class NotEnoughElementException : public std::exception
	{
		virtual char const* what() const throw();
	};

	Span(unsigned int N);
	~Span();
	Span(Span const& src);
	Span& operator=(Span const& rhs);

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void generate();

private:
	std::vector<int> vector_;
	unsigned int N_;

	Span();
};

#endif
