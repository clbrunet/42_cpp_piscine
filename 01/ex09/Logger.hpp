#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Logger {
public:
	Logger(std::string filename);

	void	log(std::string const &dest, std::string const &message);

private:
	std::string		filename_;
	std::ofstream	ofstream_;

	std::string	makeLogEntry(std::string message) const;
	void	logToConsole(std::string log);
	void	logToFile(std::string log);
};

typedef	void	(Logger::*log_action)(std::string log);

#endif
