#include "iter.hpp"

#include <iostream>

/*
class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- J'ai jamais compris pourquoi on peut pas ecrire int[] tab. Ca aurait plus de sens vous trouvez pas ?
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );
}
*/

void print_char_with_frame(char const& c)
{
	std::cout << "[" << c << "] ";
}

void print_int_multiplied_by_2(int const& n)
{
	std::cout << n * 2 << " ";
}

void print_point(Point const& point)
{
	std::cout << "x: " << point.x << " y: " << point.y << std::endl;
}

int main()
{
	std::cout << "CHAR" << std::endl;
	std::string str = "Hello world!";
	iter(str.c_str(), str.length(), &print_char_with_frame);
	std::cout << std::endl;
	iter<char>(str.c_str(), str.length(), &print_char_with_frame);
	std::cout << std::endl;

	std::cout << "\nINT" << std::endl;
	int int_arr[5] = { 0, 1, 5, 10, -25 };
	iter(int_arr, 5, &print_int_multiplied_by_2);
	std::cout << std::endl;
	iter<int>(int_arr, 5, &print_int_multiplied_by_2);
	std::cout << std::endl;

	std::cout << "\nPOINT struct" << std::endl;
	Point point[5] = {
		{ 12.5, 21.5 }, { 10.12345, 10.12345},
		{ 100, -100 }, { 0.0, 0.0 }, { -42.42, -21.21}
	};
	iter(point, 5, &print_point);
	std::cout << std::endl;
	iter<Point>(point, 5, &print_point);
}
