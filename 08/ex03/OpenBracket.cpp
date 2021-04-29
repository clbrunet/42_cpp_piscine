#include "OpenBracket.hpp"
#include "CloseBracket.hpp"

OpenBracket::OpenBracket()
{
	return;
}

OpenBracket::OpenBracket(OpenBracket const& src)
{
	static_cast<void>(src);
	return;
}

OpenBracket& OpenBracket::operator=(OpenBracket const& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

OpenBracket::~OpenBracket()
{
	return;
}

void OpenBracket::execute() const
{
	if (*ptr == 0) {
		int bracket_nb = 0;
		while (bracket_nb >= 0) {
			++cit;
			if (dynamic_cast<OpenBracket*>(*cit) != NULL) {
				bracket_nb++;
			}
			else if (dynamic_cast<CloseBracket*>(*cit) != NULL) {
				bracket_nb--;
			}
		}
	}
}
