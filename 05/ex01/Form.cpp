#include "Form.hpp"
#include "Bureaucrat.hpp"

char const* Form::GradeTooHighException::what() const throw()
{
	return "Too high grade for a Form.";
}

char const* Form::GradeTooLowException::what() const throw()
{
	return "Too low grade for a Form.";
}

Form::Form(std::string const& name, unsigned int signature_grade_required,
		unsigned int execution_grade_required)
throw(Form::GradeTooHighException, Form::GradeTooLowException)
	:	name_(name),
		is_signed_(false),
		signature_grade_required_(signature_grade_required),
		execution_grade_required_(execution_grade_required)
{
	if (signature_grade_required < HIGHEST_GRADE
			|| execution_grade_required < HIGHEST_GRADE) {
		throw Form::GradeTooHighException();
	}
	else if (signature_grade_required > LOWEST_GRADE
			|| execution_grade_required > LOWEST_GRADE) {
		throw Form::GradeTooLowException();
	}
	return;
}

Form::Form(Form const& src)
	:	name_(src.name_),
		is_signed_(src.is_signed_),
		signature_grade_required_(src.signature_grade_required_),
		execution_grade_required_(src.execution_grade_required_)
{
	return;
}

Form& Form::operator=(Form const& rhs)
{
	this->is_signed_ = rhs.is_signed_;
	return *this;
}

Form::~Form()
{
	return;
}

std::string const& Form::getName() const
{
	return this->name_;
}

bool Form::getIsSigned() const
{
	return this->is_signed_;
}

unsigned int Form::getSignatureGradeRequired() const
{
	return this->signature_grade_required_;
}

unsigned int Form::getExecutionGradeRequired() const
{
	return this->execution_grade_required_;
}

void Form::beSigned(Bureaucrat const& signatory)
		throw(Form::GradeTooLowException)
{
	if (this->signature_grade_required_ < signatory.getGrade()) {
		throw Form::GradeTooLowException();
	}
	this->is_signed_ = true;
}

Form::Form()
	:	name_(""),
		is_signed_(false),
		signature_grade_required_(HIGHEST_GRADE),
		execution_grade_required_(HIGHEST_GRADE)
{
	return;
}

std::ostream& operator<<(std::ostream& ostream, Form const& rhs)
{
	ostream << rhs.getName() << ", "
		<< (rhs.getIsSigned() ? "signed" : "unsigned")
		<< " form, grade required to sign : " << rhs.getSignatureGradeRequired()
		<< " , grade required to execute : " << rhs.getExecutionGradeRequired()
		<< ".";
	return ostream;
}
