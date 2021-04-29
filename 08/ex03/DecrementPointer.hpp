#ifndef DECREMENTPOINTER_HPP
#define DECREMENTPOINTER_HPP

#include "IInstruction.hpp"

class DecrementPointer : public IInstruction
{
public:
	DecrementPointer();
	DecrementPointer(DecrementPointer const& src);
	DecrementPointer& operator=(DecrementPointer const& rhs);
	~DecrementPointer();

	virtual void execute() const;
};

#endif
