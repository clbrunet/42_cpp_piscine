#include "eval_expr.hpp"

static bool check_expr_parenthesis(std::string expr)
{
	std::cout << expr << std::endl;
	size_t first_open_par_pos = expr.find('(');
	if (expr.find(')') < first_open_par_pos) {
		std::cout << 1 << std::endl;
		return false;
	}
	size_t last_closed_par_pos = expr.rfind(')');
	if (expr.rfind('(') > last_closed_par_pos) {
		std::cout << 2 << std::endl;
		return false;
	}
	if (first_open_par_pos != expr.npos) {
		return check_expr_parenthesis(expr.substr(first_open_par_pos + 1,
					last_closed_par_pos - first_open_par_pos - 1));
	}
	return true;
}

static bool check_expr_operations_number(char const** c_expr)
{
	while (**c_expr == ' ') {
		(*c_expr)++;
	}
	if (**c_expr == '-') {
		(*c_expr)++;
	}
	if (!isdigit(**c_expr)) {
		return false;
	}
	while (isdigit(**c_expr)) {
		(*c_expr)++;
	}
	if (**c_expr == '.') {
		(*c_expr)++;
		if (!isdigit(**c_expr)) {
			return false;
		}
		while (isdigit(**c_expr)) {
			(*c_expr)++;
		}
	}
	return true;
}

static bool check_expr_operations_operator(char const** c_expr)
{
	while (**c_expr == ' ') {
		(*c_expr)++;
	}
	if (**c_expr == '+' || **c_expr == '-'
			|| **c_expr == '*' || **c_expr == '/') {
		(*c_expr)++;
	}
	else {
		return false;
	}
	return true;
}

static bool check_expr_operations(std::string expr)
{
	size_t parenthesis_pos = expr.find_first_of("()");
	while (parenthesis_pos != expr.npos) {
		expr[parenthesis_pos] = ' ';
		parenthesis_pos = expr.find_first_of("()");
	}
	char const* c_expr = expr.c_str();
	if (check_expr_operations_number(&c_expr) == false) {
		return false;
	}
	while (*c_expr) {
		if (check_expr_operations_operator(&c_expr) == false) {
			return false;
		}
		if (check_expr_operations_number(&c_expr) == false) {
			return false;
		}
		while (*c_expr == ' ') {
			c_expr++;
		}
	}
	return true;
}

bool check_expr(std::string expr)
{
	if (expr.find_first_not_of("0123456789. +-*/()") != expr.npos) {
		std::cout << "find" << std::endl;
		return false;
	}
	if (check_expr_parenthesis(expr) == false) {
		std::cout << "()" << std::endl;
		return false;
	}
	if (check_expr_operations(expr) == false) {
		std::cout << "op" << std::endl;
		return false;
	}
	return true;
}
