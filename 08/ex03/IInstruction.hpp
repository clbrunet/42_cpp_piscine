#ifndef IINSTRUCTION_HPP
#define IINSTRUCTION_HPP

#include <vector>
#include <iostream>

class IInstruction
{
public:
	virtual ~IInstruction() {}
	virtual void execute() const = 0;
};

extern char* memory_block;
extern char* ptr;
extern std::vector<IInstruction*>::const_iterator cit;

#endif
