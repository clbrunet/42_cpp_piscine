#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void)
	: value_(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const int_value)
	: value_(int_value << 8)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const float_value)
	: value_(roundf(float_value * 256))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value_ = rhs.value_;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
