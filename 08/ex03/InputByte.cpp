#include "InputByte.hpp"

InputByte::InputByte()
{
	return;
}

InputByte::InputByte(InputByte const& src)
{
	static_cast<void>(src);
	return;
}

InputByte& InputByte::operator=(InputByte const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

InputByte::~InputByte()
{
	return;
}

void InputByte::execute() const
{
	std::cin.get(*ptr);
}
