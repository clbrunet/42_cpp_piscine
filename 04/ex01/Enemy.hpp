#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
protected:
	int hp_;
	std::string type_;

	Enemy(void);
	Enemy(Enemy const& src);
	Enemy& operator=(Enemy const& rhs);

public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	std::string const& getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

#endif
