#include "DecrementPointer.hpp"

DecrementPointer::DecrementPointer()
{
	return;
}

DecrementPointer::DecrementPointer(DecrementPointer const& src)
{
	static_cast<void>(src);
	return;
}

DecrementPointer& DecrementPointer::operator=(DecrementPointer const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

DecrementPointer::~DecrementPointer()
{
	return;
}

void DecrementPointer::execute() const
{
	if (ptr == memory_block) {
		ptr = memory_block + 29999;
	}
	else {
		ptr--;
	}
}
