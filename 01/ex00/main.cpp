#include <iostream>

#include "Pony.hpp"

static void	ponyOnTheStack(void)
{
	Pony	pony("ponyOnTheStack", "grey");
	pony.describe();
	return;
}

static void	ponyOnTheHeap(void)
{
	Pony	*pony = new Pony("ponyOnTheHeap", "brown");
	pony->describe();
	delete pony;
	return;
}

int	main(void)
{
	std::cout << "Entering main." << std::endl;
	std::cout << std::endl << "Call ponyOnTheStack." << std::endl << std::endl;
	ponyOnTheStack();
	std::cout << std::endl << "ponyOnTheStack return." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl << "Call ponyOnTheHeap." << std::endl << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl << "ponyOnTheHeap return." << std::endl;
	std::cout << std::endl << "Quitting main." << std::endl;
	return (0);
}
