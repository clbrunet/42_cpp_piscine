#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		return;
	}
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base * generate(void)
{
	std::srand(std::time(NULL));
	switch (rand() % 3) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	std::cout << "WTF" << std::endl;
	return NULL;
}

void identify_from_pointer(Base * p)
{
	A * a_ptr = dynamic_cast<A*>(p);
	if (a_ptr != NULL) {
		std::cout << "A" << std::endl;
		return;
	}
	B * b_ptr = dynamic_cast<B*>(p);
	if (b_ptr != NULL) {
		std::cout << "B" << std::endl;
		return;
	}
	C * c_ptr = dynamic_cast<C*>(p);
	if (c_ptr != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "WTF" << std::endl;
	return;
}

void identify_from_reference(Base & p)
{
	try {
		A & a_ptr = dynamic_cast<A&>(p);
		static_cast<void>(a_ptr);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {
	}
	try {
		B & b_ptr = dynamic_cast<B&>(p);
		static_cast<void>(b_ptr);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {
	}
	try {
		C & c_ptr = dynamic_cast<C&>(p);
		static_cast<void>(c_ptr);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {
	}
	std::cout << "WTF" << std::endl;
	return;
}

int main()
{
	Base * base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
