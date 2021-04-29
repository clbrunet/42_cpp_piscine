#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "Asteroid.hpp"
#include "Comet.hpp"

int main()
{
	std::cout << "With each instances !\n\n" << std::endl;

	Comet comet;
	Asteroid asteroid;
	StripMiner strip_miner;
	DeepCoreMiner deep_core_miner;
	std::cout << "Mine Comet with StripMiner :" << std::endl;
	strip_miner.mine(&comet);
	std::cout << "\nMine Comet with DeepCoreMiner :" << std::endl;
	deep_core_miner.mine(&comet);
	std::cout << "\nMine Asteroid with StripMiner :" << std::endl;
	strip_miner.mine(&asteroid);
	std::cout << "\nMine Asteroid with DeepCoreMiner :" << std::endl;
	deep_core_miner.mine(&asteroid);

	std::cout << "\n-----------------------------------"
		<< "\n\nNow with pointer to interfaces !\n" << std::endl;

	IAsteroid* i_asteroid = NULL;
	IMiningLaser* i_mining_laser = NULL;
	std::cout << "\nMine Comet with StripMiner :" << std::endl;
	i_asteroid = new Comet;
	i_mining_laser = new StripMiner;
	i_mining_laser->mine(i_asteroid);
	delete i_asteroid;
	delete i_mining_laser;
	std::cout << "\nMine Comet with DeepCoreMiner :" << std::endl;
	i_asteroid = new Comet;
	i_mining_laser = new DeepCoreMiner;
	i_mining_laser->mine(i_asteroid);
	delete i_asteroid;
	delete i_mining_laser;
	std::cout << "\nMine Asteroid with StripMiner :" << std::endl;
	i_asteroid = new Asteroid;
	i_mining_laser = new StripMiner;
	i_mining_laser->mine(i_asteroid);
	delete i_asteroid;
	delete i_mining_laser;
	std::cout << "\nMine Asteroid with DeepCoreMiner :" << std::endl;
	i_asteroid = new Asteroid;
	i_mining_laser = new DeepCoreMiner;
	i_mining_laser->mine(i_asteroid);
	delete i_asteroid;
	delete i_mining_laser;
}
