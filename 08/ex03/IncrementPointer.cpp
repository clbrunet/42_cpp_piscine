#include "IncrementPointer.hpp"

IncrementPointer::IncrementPointer()
{
	return;
}

IncrementPointer::IncrementPointer(IncrementPointer const& src)
{
	static_cast<void>(src);
	return;
}

IncrementPointer& IncrementPointer::operator=(IncrementPointer const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

IncrementPointer::~IncrementPointer()
{
	return;
}

void IncrementPointer::execute() const
{
	if (ptr == memory_block + 29999) {
		ptr = memory_block;
	}
	else {
		ptr++;
	}
}
