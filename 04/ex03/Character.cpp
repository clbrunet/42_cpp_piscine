#include "Character.hpp"

Character::Character()
	:	_name(""),
		_nb_materias(0)
{
	return;
}

Character::Character(std::string name)
	:	_name(name),
		_nb_materias(0)
{
	return;
}


Character::Character(Character const& src)
{
	*this = src;
	return;
}

Character& Character::operator=(Character const& rhs)
{
	for (unsigned int i = 0; i < this->_nb_materias; i++) {
		delete this->_inventory[i];
	}
	this->_nb_materias = rhs._nb_materias;
	for (unsigned int i = 0; i < rhs._nb_materias; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (unsigned int i = 0; i < this->_nb_materias; i++) {
		delete this->_inventory[i];
	}
	return;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL || this->_nb_materias == 4) {
		return;
	}
	this->_inventory[this->_nb_materias] = m;
	this->_nb_materias++;
	return;
}

void Character::unequip(int idx)
{
	if ((unsigned int)idx >= this->_nb_materias) {
		return;
	}
	for (unsigned int i = idx; i < this->_nb_materias - 1; i++) {
		this->_inventory[i] = this->_inventory[i + 1];
	}
	this->_nb_materias--;
}

void Character::use(int idx, ICharacter& target)
{
	if ((unsigned int)idx >= this->_nb_materias) {
		return;
	}
	this->_inventory[idx]->use(target);
}
