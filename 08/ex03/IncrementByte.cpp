#include "IncrementByte.hpp"

IncrementByte::IncrementByte()
{
	return;
}

IncrementByte::IncrementByte(IncrementByte const& src)
{
	static_cast<void>(src);
	return;
}

IncrementByte& IncrementByte::operator=(IncrementByte const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

IncrementByte::~IncrementByte()
{
	return;
}

void IncrementByte::execute() const
{
	(*ptr)++;
}
