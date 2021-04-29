#ifndef INCREMENTPOINTER_HPP
#define INCREMENTPOINTER_HPP

#include "IInstruction.hpp"

class IncrementPointer : public IInstruction
{
public:
	IncrementPointer();
	IncrementPointer(IncrementPointer const& src);
	IncrementPointer& operator=(IncrementPointer const& rhs);
	~IncrementPointer();

	virtual void execute() const;
};

#endif
