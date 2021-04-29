#include "OutputByte.hpp"

OutputByte::OutputByte()
{
	return;
}

OutputByte::OutputByte(OutputByte const& src)
{
	static_cast<void>(src);
	return;
}

OutputByte& OutputByte::operator=(OutputByte const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

OutputByte::~OutputByte()
{
	return;
}

void OutputByte::execute() const
{
	std::cout << *ptr;
}
