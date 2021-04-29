#include "Logger.hpp"

int	main(void)
{
	Logger logger("file.log");

	logger.log("console", "Hello console !");
	logger.log("file", "Hello file !");
	logger.log("nowhere", "Hello nowhere !");
	return (0);
}
