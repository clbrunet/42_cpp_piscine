#include <cctype>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <cerrno>

enum LitteralType
{
	kNone,
	kChar,
	kInt,
	kFloat,
	kDouble
};

LitteralType GetLitteralType(std::string litteral)
{
	if (litteral.length() == 1 && !std::isdigit(litteral[0])) {
		return kChar;
	}
	if (litteral.find_first_of("-+") == 0) {
		litteral.erase(0, 1);
	}
	if (litteral == "inff" || litteral == "nanf") {
		return kFloat;
	}
	else if (litteral == "inf" || litteral == "nan") {
		return kDouble;
	}
	size_t pos = litteral.find_first_not_of("0123456789");
	if (pos == litteral.npos) {
		return kInt;
	}
	else if (pos == 0 || litteral[pos] != '.' || pos + 1 == litteral.length()) {
		return kNone;
	}
	litteral = litteral.substr(pos + 1);
	pos = litteral.find_first_not_of("0123456789");
	if (pos == litteral.npos) {
		return kDouble;
	}
	else if (pos != 0 && litteral[pos] == 'f'
			&& pos + 1 == litteral.length()) {
		return kFloat;
	}
	return kNone;
}

void CharCase(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void IntCase(long int i)
{
	if (errno == ERANGE || i < INT_MIN || INT_MAX < i) {
		std::cout << "The integer litteral overflow or underflow." << std::endl;
		return;
	}
	std::cout << "char: ";
	if (i < static_cast<long int>(CHAR_MIN)
			|| static_cast<long int>(CHAR_MAX) < i) {
		std::cout << "impossible" << std::endl;
	}
	else if (i < static_cast<long int>(32) || static_cast<long int>(126) < i) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << static_cast<char>(i) << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void FloatCase(float f)
{
	if (errno == ERANGE) {
		std::cout << "The float litteral overflow or underflow." << std::endl;
		return;
	}
	std::cout << "char: ";
	if (f < static_cast<float>(CHAR_MIN)
			|| static_cast<float>(CHAR_MAX) < f || f != f) {
		std::cout << "impossible" << std::endl;
	}
	else if (f < static_cast<float>(32) || static_cast<float>(126) < f) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << static_cast<char>(f) << std::endl;
	}
	std::cout << "int: ";
	if (f < static_cast<float>(INT_MIN) || static_cast<float>(INT_MAX) < f
			|| f != f) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void DoubleCase(double d)
{
	if (errno == ERANGE) {
		std::cout << "The double litteral overflow or underflow." << std::endl;
		return;
	}
	std::cout << "char: ";
	if (d < static_cast<double>(CHAR_MIN)
			|| static_cast<double>(CHAR_MAX) < d || d != d) {
		std::cout << "impossible" << std::endl;
	}
	else if (d < static_cast<double>(32) || static_cast<double>(126) < d) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << static_cast<char>(d) << std::endl;
	}
	std::cout << "int: ";
	if (d < static_cast<double>(INT_MIN) || static_cast<double>(INT_MAX) < d
			|| d != d) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: ";
	if (d < static_cast<double>(FLT_MIN) || static_cast<double>(FLT_MAX) < d) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<float>(d) << "f" << std::endl;
	}
	std::cout << "double: " << d << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0') {
		std::cout << "convert usage : ./convert <litteral>" << std::endl;
		return 1;
	}
	std::cout << std::setprecision(1) << std::fixed;
	switch (GetLitteralType(argv[1])) {
		case kChar:
			CharCase(argv[1][0]);
			break;
		case kInt:
			IntCase(strtol(argv[1], NULL, 10));
			break;
		case kFloat:
			FloatCase(strtof(argv[1], NULL));
			break;
		case kDouble:
			DoubleCase(strtod(argv[1], NULL));
			break;
		default:
			std::cout << "Wrong litteral format." << std::endl;
			return 1;
	}
	return 0;
}
