#ifndef CLOSEBRACKET_HPP
#define CLOSEBRACKET_HPP

#include "IInstruction.hpp"

class CloseBracket : public IInstruction
{
public:
	CloseBracket();
	CloseBracket(CloseBracket const& src);
	CloseBracket& operator=(CloseBracket const& rhs);
	~CloseBracket();

	virtual void execute() const;
};

#endif
