#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
	:	hp_(hp),
		type_(type)
{
	return;
}

Enemy::~Enemy()
{
	return;
}

std::string const& Enemy::getType() const
{
	return this->type_;
}

int Enemy::getHP() const
{
	return this->hp_;
}

void Enemy::takeDamage(int amount)
{
	if (amount < 0) {
		return;
	}
	else if (amount > this->hp_) {
		this->hp_ = 0;
	}
	else {
		this->hp_ -= amount;
	}
}

Enemy::Enemy(void)
	:	hp_(0),
		type_("")
{
	return;
}

Enemy::Enemy(Enemy const& src)
{
	*this = src;
	return;
}

Enemy& Enemy::operator=(Enemy const& rhs)
{
	this->hp_ = rhs.hp_;
	this->type_ = rhs.type_;
	return *this;
}
