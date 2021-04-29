#include "Bureaucrat.hpp"
#include "Form.hpp"

char const* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Too high grade for a Bureaucrat.";
}

char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Too low grade for a Bureaucrat.";
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade)
throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
	:	name_(name),
		grade_(grade)
{
	if (grade < HIGHEST_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > LOWEST_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
	:	name_(src.name_),
		grade_(src.grade_)
{
	return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
	this->grade_ = rhs.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

std::string const& Bureaucrat::getName() const
{
	return this->name_;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->grade_;
}

void Bureaucrat::riseUp() throw(Bureaucrat::GradeTooHighException)
{
	if (this->grade_ == HIGHEST_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_--;
}

void Bureaucrat::riseDown() throw(Bureaucrat::GradeTooLowException)
{
	if (this->grade_ == LOWEST_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_++;
}

void Bureaucrat::signForm(Form& form) const
{
	try {
		form.beSigned(*this);
		std::cout << this->name_ << " signs " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << this->name_ << " cannot sign " << form.getName() << " because "
			<< e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat()
	:	name_(""),
		grade_(LOWEST_GRADE)
{
	return;
}

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& rhs)
{
	ostream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
		<< ".";
	return ostream;
}
