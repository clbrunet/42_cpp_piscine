#ifndef DECREMENTBYTE_HPP
#define DECREMENTBYTE_HPP

#include "IInstruction.hpp"

class DecrementByte : public IInstruction
{
public:
	DecrementByte();
	DecrementByte(DecrementByte const& src);
	DecrementByte& operator=(DecrementByte const& rhs);
	~DecrementByte();

	virtual void execute() const;
};

#endif
