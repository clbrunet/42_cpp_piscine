#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <stdexcept>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class Form
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

	Form(std::string const& name, unsigned int signature_grade_required,
			unsigned int execution_grade_required)
		throw(Form::GradeTooHighException, Form::GradeTooLowException);
	Form(Form const& src);
	Form& operator=(Form const& rhs);
	virtual ~Form();

	std::string const& getName() const;
	bool getIsSigned() const;
	unsigned int getSignatureGradeRequired() const;
	unsigned int getExecutionGradeRequired() const;

	void beSigned(Bureaucrat const& signatory)
		throw(Form::GradeTooLowException);

private:
	std::string const name_;
	bool is_signed_;
	unsigned int const signature_grade_required_;
	unsigned int const execution_grade_required_;

	Form();
};

std::ostream& operator<<(std::ostream& ostream, Form const& rhs);

#endif
