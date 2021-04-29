#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const& src);
	~Fixed(void);

	Fixed& operator=(Fixed const& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int value_;
	static int const nb_fractional_bits_;
};

std::ostream&	operator<<(std::ostream& ostream, Fixed const& rhs);

#endif
