#include <cerrno>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

static void cat_stdin(void)
{
	std::string buf = "";
	while (!std::cin.bad() && !std::cin.eof()) {
		std::getline(std::cin, buf);
		if (!std::cin.eof())
			buf += "\n";
		std::cout << buf;
	}
}

static bool cat_file(char *filename)
{
	std::ifstream	ifstream(filename);
	if (!ifstream.is_open()) {
		std::cerr << "cat: " << filename << ": "
			<< std::strerror(errno) << std::endl;
		return false;
	}
	std::string file_content = "";
	std::string buf = "";
	while (!ifstream.bad() && !ifstream.eof()) {
		std::getline(ifstream, buf);
		file_content += buf;
		if (!ifstream.eof())
			file_content += "\n";
	}
	std::cout << file_content;
	return true;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	if (argc == 1) {
		cat_stdin();
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (cat_file(argv[i]) == false) {
				ret = 1;
			}
		}
	}
	return ret;
}
