#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <stdexcept>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual char const* what() const throw ();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual char const* what() const throw ();
	};
	Bureaucrat(std::string const& name, unsigned int grade)
		throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat(Bureaucrat const& src);
	Bureaucrat& operator=(Bureaucrat const& rhs);
	virtual ~Bureaucrat();

	std::string const& getName() const;
	unsigned int getGrade() const;

	void riseUp() throw(Bureaucrat::GradeTooHighException);
	void riseDown() throw(Bureaucrat::GradeTooLowException);

private:
	std::string const name_;
	unsigned int grade_;

	Bureaucrat();
};

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& rhs);

#endif
