#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const& src);
	~Fixed(void);

	Fixed& operator=(Fixed const& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int value_;
	static int const nb_fractional_bits_;
};

#endif
