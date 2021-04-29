#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array() :
		array_(NULL),
		size_(0)
	{
		return;
	}

	Array(unsigned int n) :
		array_(new T[n]()),
		size_(n)
	{
		return;
	}

	Array(Array const& src) :
		array_(NULL),
		size_(0)
	{
		*this = src;
		return;
	}

	Array& operator=(Array const& rhs)
	{
		if (this->size_ != 0) {
			delete [] this->array_;
		}
		this->array_ = new T[rhs.size_]();
		for (std::size_t i = 0; i < rhs.size_; i++) {
			this->array_[i] = rhs.array_[i];
		}
		this->size_ = rhs.size_;
		return *this;
	}

	~Array()
	{
		if (this->size_ != 0) {
			delete [] this->array_;
		}
		return;
	}

	class OutOfLimitsException : public std::exception
	{
		virtual char const* what() const throw()
		{
			return "try to access an out of limits index";
		}
	};

	T& operator[](std::size_t idx) const
	{
		if (idx >= this->size_) {
			throw Array::OutOfLimitsException();
		}
		return this->array_[idx];
	}

	std::size_t size() const
	{
		return this->size_;
	}

private:
	T* array_;
	std::size_t size_;
};

#endif
