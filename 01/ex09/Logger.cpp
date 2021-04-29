#include "Logger.hpp"

Logger::Logger(std::string filename)
	:	filename_(filename),
		ofstream_(filename.c_str(), std::ios_base::app)
{
	return;
}

void	Logger::log(std::string const &dest, std::string const &message)
{
	log_action log_actions[2] = { &Logger::logToConsole, &Logger::logToFile };
	std::string dests[2] = { "console", "file" };
	for (int i = 0; i < 2; i++) {
		if (dests[i] == dest)
			return ((this->*log_actions[i])(makeLogEntry(message)));
	}
	return;
}

std::string	Logger::makeLogEntry(std::string message) const
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::stringstream log;
	log << ((ltm->tm_mday < 10) ? "0" : "") << ltm->tm_mday << "/"
		<< ((ltm->tm_mon < 10) ? "0" : "") << ltm->tm_mon << "/"
		<< 1900 + ltm->tm_year << " "
		<< ((ltm->tm_hour < 10) ? "0" : "") << ltm->tm_hour << ":"
		<< ((ltm->tm_min < 10) ? "0" : "") << ltm->tm_min << ":"
		<< ((ltm->tm_sec < 10) ? "0" : "") << ltm->tm_sec
		<< " : " << message;
	return (log.str());
}

void	Logger::logToConsole(std::string log)
{
	std::cout << log << std::endl;
	return;
}

void	Logger::logToFile(std::string log)
{
	this->ofstream_ << log << std::endl;
	return;
}
