#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "instructions.hpp"

char* memory_block = NULL;
char* ptr = NULL;
std::vector<IInstruction*> instructions;
std::vector<IInstruction*>::const_iterator cit;

bool check_source_file(std::string const& file_content)
{
	if (file_content.find_first_not_of("><+-oi[]\n\t ") != file_content.npos) {
		std::cout << "Source file chars error" << std::endl;
		return false;
	}
	int bracket_nb = 0;
	size_t pos = 0;
	while ((pos = file_content.find_first_of("[]", pos)) != file_content.npos) {
		if (file_content[pos] == '[') {
			bracket_nb++;
		}
		else if (bracket_nb != 0) {
			bracket_nb--;
		}
		else {
			std::cout << "Source file brackets error" << std::endl;
			return false;
		}
		pos++;
	}
	if (bracket_nb != 0) {
		std::cout << "Source file brackets error" << std::endl;
		return false;
	}
	return true;
}

void parse_instructions(std::string const& file_content)
{
	for (std::string::const_iterator cit = file_content.begin(),
			cite = file_content.end(); cit != cite; ++cit) {
		switch (*cit) {
			case '>':
				instructions.push_back(new IncrementPointer());
				break;
			case '<':
				instructions.push_back(new DecrementPointer());
				break;
			case '+':
				instructions.push_back(new IncrementByte());
				break;
			case '-':
				instructions.push_back(new DecrementByte());
				break;
			case 'o':
				instructions.push_back(new OutputByte());
				break;
			case 'i':
				instructions.push_back(new InputByte());
				break;
			case '[':
				instructions.push_back(new OpenBracket());
				break;
			case ']':
				instructions.push_back(new CloseBracket());
				break;
		}
    }
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "mindopen usage : path/mindopen <filename>" << std::endl;
		return 1;
	}
	std::ifstream ifs(argv[1]);
	if (ifs.is_open() == false) {
		std::cout << "Cannot open " << argv[1] << "." << std::endl;
		return 2;
	}
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	std::string file_content(buffer.str());
	if (check_source_file(file_content) == false) {
		return 3;
	}
	parse_instructions(file_content);
	try {
		memory_block = new char[30000]();
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
		return 4;
	}
	ptr = memory_block;
	cit = instructions.begin();
	for (std::vector<IInstruction*>::const_iterator cite = instructions.end();
			cit != cite; ++cit) {
		(*cit)->execute();
	}
	delete [] memory_block;
	for (std::vector<IInstruction*>::iterator it = instructions.begin(),
			ite = instructions.end(); it != ite; ++it) {
		delete *it;
	}
	return 0;
}
