#include "CloseBracket.hpp"
#include "OpenBracket.hpp"

CloseBracket::CloseBracket()
{
	return;
}

CloseBracket::CloseBracket(CloseBracket const& src)
{
	static_cast<void>(src);
	return;
}

CloseBracket& CloseBracket::operator=(CloseBracket const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

CloseBracket::~CloseBracket()
{
	return;
}

void CloseBracket::execute() const
{
	if (*ptr != 0) {
		int bracket_nb = 0;
		while (bracket_nb >= 0) {
			--cit;
			if (dynamic_cast<CloseBracket*>(*cit) != NULL) {
				bracket_nb++;
			}
			else if (dynamic_cast<OpenBracket*>(*cit) != NULL) {
				bracket_nb--;
			}
		}
	}
}
