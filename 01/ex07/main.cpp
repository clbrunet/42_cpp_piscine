#include <string>
#include <iostream>
#include <fstream>

static bool	read_file(std::string filename, std::string &file_content)
{
	std::ifstream	ifstream(filename.c_str());
	if (!ifstream.is_open()) {
		std::cout << "Failed to open " << filename << "." << std::endl;
		return (false);
	}
	std::string		buf = "";
	while (!ifstream.bad() && !ifstream.eof())
	{
		std::getline(ifstream, buf);
		file_content += buf;
		if (!ifstream.eof())
			file_content += "\n";
	}
	return (true);
}

static void	replace(std::string filename, std::string s1, std::string s2)
{
	std::string		file_content = "";
	if (read_file(filename, file_content) == false)
		return;
	std::ofstream	ofstream((filename + ".replace").c_str());
	size_t			pos = file_content.find(s1, 0);
	while (pos != std::string::npos) {
		file_content.replace(pos, s1.length(), s2);
		pos = file_content.find(s1, pos + s2.length());
	}
	ofstream << file_content;
}

int	main(int argc, char *argv[])
{
	if (argc < 4) {
		std::cout << "replace usage :" << std::endl
			<< "  ./replace filename s1 s2" << std::endl;
		return (1);
	}
	else if (!*argv[1] || !*argv[2] || !*argv[3]) {
		std::cout << "Parameters cannot be empty" << std::endl;
		return (1);
	}
	replace(argv[1], argv[2], argv[3]);
	return (0);
}
