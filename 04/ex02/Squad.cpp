#include "Squad.hpp"

Squad::Squad()
	:	count_(0),
	units_(NULL)
{
	return;
}

Squad::Squad(Squad const& src)
{
	*this = src;
	return;
}

Squad::~Squad()
{
	for (int i = 0; i < this->count_; i++) {
		delete this->units_[i];
	}
	if (this->count_ != 0) {
		delete [] this->units_;
	}
	return;
}

Squad& Squad::operator=(Squad const& rhs)
{
	this->count_ = rhs.count_;
	if (this->count_ == 0) {
		this->units_ = NULL;
	}
	else {
		this->units_ = new ISpaceMarine*[this->count_];
		for (int i = 0; i < this->count_; i++) {
			this->units_[i] = rhs.units_[i]->clone();
		}
	}
	return *this;
}

int Squad::getCount() const
{
	return this->count_;
}

ISpaceMarine* Squad::getUnit(int n) const
{
	if (n < 0 || this->count_ <= n) {
		return NULL;
	}
	return this->units_[n];
}

int Squad::push(ISpaceMarine* new_space_marine)
{
	if (new_space_marine == NULL) {
		return this->count_;
	}
	for (int i = 0; i < this->count_; i++) {
		if (new_space_marine == this->units_[i]) {
			return this->count_;
		}
	}
	ISpaceMarine** new_units = new ISpaceMarine*[this->count_ + 1];
	for (int i = 0; i < this->count_; i++) {
		new_units[i] = this->units_[i];
	}
	new_units[this->count_] = new_space_marine;
	if (this->count_ != 0) {
		delete [] this->units_;
	}
	this->count_++;
	this->units_ = new_units;
	return this->count_;
}
