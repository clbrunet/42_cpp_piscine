#ifndef OUTPUTBYTE_HPP
#define OUTPUTBYTE_HPP

#include "IInstruction.hpp"

class OutputByte : public IInstruction
{
public:
	OutputByte();
	OutputByte(OutputByte const& src);
	OutputByte& operator=(OutputByte const& rhs);
	~OutputByte();

	virtual void execute() const;
};

#endif
