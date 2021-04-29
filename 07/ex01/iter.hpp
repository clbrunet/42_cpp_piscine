#ifndef ITER_HPP
#define ITER_HPP

struct Point
{
	double x;
	double y;
};

template <typename T>
void iter(T const* array, int length, void (*f)(T const&))
{
	for (int i = 0; i < length; i++) {
		(*f)(array[i]);
	}
}

#endif
