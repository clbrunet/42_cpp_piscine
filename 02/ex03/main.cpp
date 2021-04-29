#include "eval_expr.hpp"

static std::string get_parenthesis_result_calculations(std::string expr)
{
	std::stringstream expr_stream(expr);
	std::stringstream next_expr_stream;
	float lhs = 0;
	float rhs = 0;
	char c_operator = 0;
	while (expr_stream.str().find_first_of("*/+") != std::string::npos
			|| (expr_stream.str().rfind('-') != std::string::npos
				&& expr_stream.str().rfind('-') != 0)) {
		next_expr_stream.str("");
		next_expr_stream.clear();
		expr_stream >> lhs >> c_operator >> rhs;
		if (expr_stream.str().find_first_of("*/") != std::string::npos) {
			while (c_operator != '*' && c_operator != '/') {
				next_expr_stream << lhs << c_operator;
				lhs = rhs;
				expr_stream >> c_operator >> rhs;
			}
		}
		if (c_operator == '*') {
			next_expr_stream << Fixed(lhs) * Fixed(rhs);
		}
		else if (c_operator == '/') {
			next_expr_stream << Fixed(lhs) / Fixed(rhs);
		}
		else if (c_operator == '+') {
			next_expr_stream << Fixed(lhs) + Fixed(rhs);
		}
		else {
			next_expr_stream << Fixed(lhs) - Fixed(rhs);
		}
		std::string rest = "";
		std::getline(expr_stream, rest);
		next_expr_stream << rest;
		expr_stream.str(next_expr_stream.str());
		expr_stream.clear();
	}
	return expr_stream.str();
}

static std::string get_parenthesis_result(std::string expr)
{
	if (expr.length() == 0)
		return "";
	size_t parenthesis_pos = expr.find('(');
	std::string result;
	while (parenthesis_pos != expr.npos) {
		size_t len = expr.find(')') - (parenthesis_pos + 1);
		result = get_parenthesis_result(expr.substr(parenthesis_pos + 1, len));
		expr.replace(parenthesis_pos, len + 2, result);
		parenthesis_pos = expr.find('(');
	}
	return get_parenthesis_result_calculations(expr);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "eval_expr usage :\n"
			<< "  ./eval_expr expression\n";
		return 1;
	}
	if (check_expr(argv[1]) == false) {
		std::cout << "Wrong expression format.\n";
		return 1;
	}
	std::cout << get_parenthesis_result(argv[1]) << std::endl;
	return 0;
}
