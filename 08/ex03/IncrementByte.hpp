#ifndef INCREMENTBYTE_HPP
#define INCREMENTBYTE_HPP

#include "IInstruction.hpp"

class IncrementByte : public IInstruction
{
public:
	IncrementByte();
	IncrementByte(IncrementByte const& src);
	IncrementByte& operator=(IncrementByte const& rhs);
	~IncrementByte();

	virtual void execute() const;
};

#endif
