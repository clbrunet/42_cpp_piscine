#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	:	_nb_materias(0)
{
	return;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	*this = src;
	return;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	for (unsigned int i = 0; i < this->_nb_materias; i++) {
		delete this->_materias[i];
	}
	this->_nb_materias = rhs._nb_materias;
	for (unsigned int i = 0; i < rhs._nb_materias; i++) {
		this->_materias[i] = rhs._materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (unsigned int i = 0; i < this->_nb_materias; i++) {
		delete this->_materias[i];
	}
	return;
}
void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL || this->_nb_materias == 4) {
		return;
	}
	this->_materias[this->_nb_materias] = m;
	this->_nb_materias++;
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = this->_nb_materias - 1; i >= 0; i--) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}
