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

	bool operator>(Fixed const& rhs) const;
	bool operator<(Fixed const& rhs) const;
	bool operator>=(Fixed const& rhs) const;
	bool operator<=(Fixed const& rhs) const;
	bool operator==(Fixed const& rhs) const;
	bool operator!=(Fixed const& rhs) const;

	Fixed operator+(Fixed const& rhs) const;
	Fixed operator-(Fixed const& rhs) const;
	Fixed operator*(Fixed const& rhs) const;
	Fixed operator/(Fixed const& rhs) const;

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static Fixed const& min(Fixed const& f1, Fixed const& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static Fixed const& max(Fixed const& f1, Fixed const& f2);

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
