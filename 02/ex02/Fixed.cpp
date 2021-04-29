#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void)
	: value_(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const int_value)
	: value_(int_value << 8)
{
	// std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const float_value)
	: value_(roundf(float_value * 256))
{
	// std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const& src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->value_ = rhs.value_;
	return *this;
}

bool Fixed::operator>(Fixed const& rhs) const
{
	// std::cout << "Greater than operator called" << std::endl;
	return this->value_ > rhs.value_;
}

bool Fixed::operator<(Fixed const& rhs) const
{
	// std::cout << "Less than operator called" << std::endl;
	return this->value_ < rhs.value_;
}

bool Fixed::operator>=(Fixed const& rhs) const
{
	// std::cout << "Greater than or equal to operator called" << std::endl;
	return this->value_ >= rhs.value_;
}

bool Fixed::operator<=(Fixed const& rhs) const
{
	// std::cout << "Less than or equal to operator called" << std::endl;
	return this->value_ <= rhs.value_;
}

bool Fixed::operator==(Fixed const& rhs) const
{
	// std::cout << "Equal to operator called" << std::endl;
	return this->value_ == rhs.value_;
}

bool Fixed::operator!=(Fixed const& rhs) const
{
	// std::cout << "Not equal to operator called" << std::endl;
	return this->value_ != rhs.value_;
}

Fixed Fixed::operator+(Fixed const& rhs) const
{
	// std::cout << "Addition operator called" << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const& rhs) const
{
	// std::cout << "Substraction operator called" << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
	// std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const& rhs) const
{
	// std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void)
{
	// std::cout << "Pre-increment operator called" << std::endl;
	this->value_++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	// std::cout << "Post-increment operator called" << std::endl;
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed& Fixed::operator--(void)
{
	// std::cout << "Pre-decrement operator called" << std::endl;
	this->value_--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	// std::cout << "Post-decrement operator called" << std::endl;
	Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2) {
		return f1;
	}
	return f2;
}

Fixed const& Fixed::min(Fixed const& f1, Fixed const& f2)
{
	if (f1 < f2) {
		return f1;
	}
	return f2;
}


Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2) {
		return f1;
	}
	return f2;
}

Fixed const& Fixed::max(Fixed const& f1, Fixed const& f2)
{
	if (f1 > f2) {
		return f1;
	}
	return f2;
}
int Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return this->value_;
}

void Fixed::setRawBits(int const raw)
{
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->value_ = raw;
	return;
}

float Fixed::toFloat(void) const
{
	return (float)this->value_ / 256;
}

int Fixed::toInt(void) const
{
	return this->value_ >> 8;
}

int const Fixed::nb_fractional_bits_ = 8;

std::ostream&	operator<<(std::ostream& ostream, Fixed const& rhs)
{
	ostream << rhs.toFloat();
	return ostream;
}
