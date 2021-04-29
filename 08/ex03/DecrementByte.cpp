#include "DecrementByte.hpp"

DecrementByte::DecrementByte()
{
	return;
}

DecrementByte::DecrementByte(DecrementByte const& src)
{
	static_cast<void>(src);
	return;
}

DecrementByte& DecrementByte::operator=(DecrementByte const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

DecrementByte::~DecrementByte()
{
	return;
}

void DecrementByte::execute() const
{
	(*ptr)--;
}
