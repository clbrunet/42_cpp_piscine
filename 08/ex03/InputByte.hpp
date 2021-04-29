#ifndef INPUTBYTE_HPP
#define INPUTBYTE_HPP

#include "IInstruction.hpp"

class InputByte : public IInstruction
{
public:
	InputByte();
	InputByte(InputByte const& src);
	InputByte& operator=(InputByte const& rhs);
	~InputByte();

	virtual void execute() const;
};

#endif
