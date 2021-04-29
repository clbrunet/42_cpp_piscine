#include <iostream>
#include <cstdlib>
#include <ctime>

struct Data { std::string s1; int n; std::string s2; };

void * serialize(void)
{
	Data* data = new Data;
	std::srand(std::time(NULL));
	data->s1.resize(8);
	data->n = rand();
	data->s2.resize(8);
	std::string alnum("0123456789qwertyuiopasdfghjklzxcvbnm");
	for (int i = 0; i < 8; i++) {
		data->s1[i] = alnum[rand() % alnum.length()];
		data->s2[i] = alnum[rand() % alnum.length()];
	}
	return reinterpret_cast<void*>(data);
}

Data * deserialize(void * raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	void* raw = serialize();
	Data* data = deserialize(raw);
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;
	delete data;
	return 0;
}
