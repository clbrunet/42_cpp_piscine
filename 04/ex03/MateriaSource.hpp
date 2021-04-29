#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const& src);
	MateriaSource& operator=(MateriaSource const& rhs);
	virtual ~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	unsigned int _nb_materias;
	AMateria* _materias[4];
};

#endif
