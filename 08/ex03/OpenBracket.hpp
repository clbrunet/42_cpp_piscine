#ifndef OPENBRACKET_HPP
#define OPENBRACKET_HPP

#include "IInstruction.hpp"

class OpenBracket : public IInstruction
{
public:
	OpenBracket();
	OpenBracket(OpenBracket const& src);
	OpenBracket& operator=(OpenBracket const& rhs);
	~OpenBracket();

	virtual void execute() const;
};

#endif
