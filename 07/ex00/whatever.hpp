#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

class Point
{
public:
	Point(double x, double y) : x_(x), y_(y) {}
	Point(Point const& src) { *this = src; }
	Point& operator=(Point const& rhs)
	{
		this->x_ = rhs.x_;
		this->y_ = rhs.y_;
		return *this;
	}

	bool operator==(Point const& rhs) const
	{
		if (this->x_ == rhs.x_ && this->y_ == rhs.y_)
			return true;
		return false;
	}
	bool operator!=(Point const& rhs) const
	{
		if (this->x_ != rhs.x_ && this->y_ != rhs.y_)
			return false;
		return true;
	}
	bool operator>(Point const& rhs) const
	{
		if (this->x_ > rhs.x_ && this->y_ > rhs.y_)
			return true;
		return false;
	}
	bool operator>=(Point const& rhs) const
	{
		if (this->x_ >= rhs.x_ && this->y_ >= rhs.y_)
			return true;
		return false;
	}
	bool operator<(Point const& rhs) const
	{
		if (this->x_ < rhs.x_ && this->y_ < rhs.y_)
			return true;
		return false;
	}
	bool operator<=(Point const& rhs) const
	{
		if (this->x_ <= rhs.x_ && this->y_ <= rhs.y_)
			return true;
		return false;
	}

	double x() const { return this->x_; }
	double y() const { return this->y_; }

private:
	double x_;
	double y_;

	Point();
};

std::ostream& operator<<(std::ostream& ostream, Point const& rhs)
{
	ostream << "X: " << rhs.x() << " Y: " << rhs.y();
	return ostream;
}

template <typename T>
void swap(T& first, T& second)
{
	T tmp = first;
	first = second;
	second = tmp;
	return;
}

template <typename T>
T const& min(T const& first, T const& second)
{
	if (first < second) {
		return first;
	}
	else {
		return second;
	}
}

template <typename T>
T const& max(T const& first, T const& second)
{
	if (first > second) {
		return first;
	}
	else {
		return second;
	}
}

#endif
