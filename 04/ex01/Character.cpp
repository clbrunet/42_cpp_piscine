#include "Character.hpp"

Character::Character(void)
	:	name_(""),
		ap_(0),
		weapon_(NULL)
{
	return;
}

Character::Character(std::string const & name)
	:	name_(name),
		ap_(40),
		weapon_(NULL)
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
	this->name_ = rhs.name_;
	this->ap_ = rhs.ap_;
	this->weapon_ = rhs.weapon_;
	return *this;
}

Character::~Character()
{
	return;
}

void Character::recoverAP()
{
	if (this->ap_ > 30) {
		this->ap_ = 40;
	}
	else {
		this->ap_ += 10;
	}
}

void Character::equip(AWeapon* weapon)
{
	this->weapon_ = weapon;
}

void Character::attack(Enemy* enemy)
{
	if (this->weapon_ == NULL || this->ap_ < this->weapon_->getAPCost()) {
		return;
	}
	std::cout << this->name_ << " attacks " << enemy->getType()
		<< " with a " << this->weapon_->getName() << std::endl;
	this->ap_ -= this->weapon_->getAPCost();
	this->weapon_->attack();
	enemy->takeDamage(this->weapon_->getDamage());
	if (enemy->getHP() == 0) {
		delete enemy;
	}
}

std::string const& Character::getName() const
{
	return this->name_;
}

int Character::getAP() const
{
	return this->ap_;
}

AWeapon const* Character::getWeapon() const
{
	return this->weapon_;
}

std::ostream& operator<<(std::ostream& ostream, Character const& rhs)
{
	ostream << rhs.getName() << " has " << rhs.getAP() << " AP and ";
	AWeapon const* rhs_weapon = rhs.getWeapon();
	if (rhs_weapon == NULL) {
		std::cout << "is unarmed" << std::endl;
	}
	else {
		std::cout << "wields a " << rhs_weapon->getName() << std::endl;
	}
	return ostream;
}
