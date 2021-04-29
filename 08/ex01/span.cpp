#include "span.hpp"

char const* Span::ExceedMaxNumbersException::what() const throw()
{
	return "attempts to store a number in a filled span object";
}

char const* Span::NotEnoughElementException::what() const throw()
{
	return "not enough element to calculate a span";
}

Span::Span(unsigned int N)
	:	N_(N)
{
	return;
}

Span::~Span()
{
	return;
}

Span::Span(Span const& src)
{
	*this = src;
	return;
}

Span& Span::operator=(Span const& rhs)
{
	this->vector_ = std::vector<int>(rhs.vector_);
	this->N_ = rhs.N_;
	return *this;
}

void Span::addNumber(int number)
{
	if (this->vector_.size() == this->N_) {
		throw Span::ExceedMaxNumbersException();
	}
	this->vector_.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (this->vector_.size() < 2) {
		throw Span::NotEnoughElementException();
	}
	std::vector<int> copy (this->vector_);
	std::sort(copy.begin(), copy.end());
	unsigned int shortest_span = UINT_MAX;
	for (std::vector<int>::const_iterator cit = copy.begin(),
			end = copy.end() - 1; cit != end; ++cit) {
		unsigned int current_span = *(cit + 1) - *cit;
		if (current_span < shortest_span) {
			shortest_span = current_span;
		}
	}
	return shortest_span;
}

unsigned int Span::longestSpan() const
{
	if (this->vector_.size() < 2) {
		throw Span::NotEnoughElementException();
	}
	return *std::max_element(this->vector_.begin(), this->vector_.end())
		- *std::min_element(this->vector_.begin(), this->vector_.end());
}

void Span::generate()
{
	while (this->vector_.size() < this->N_) {
		this->vector_.push_back(std::rand());
	}
}

Span::Span()
	:	N_(0)
{
	return;
}
