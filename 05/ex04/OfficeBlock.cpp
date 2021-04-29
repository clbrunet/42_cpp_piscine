#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

char const* OfficeBlock::OfficeBlockIsntFilledException::what() const throw()
{
	return "OfficeBlock lacks members.";
}

char const* OfficeBlock::UnknownFormNameException::what() const throw()
{
	return "unknown form name.";
}

char const* OfficeBlock::SignatoryGradeTooLowExecption::what() const throw()
{
	return "signatory grade too low.";
}

char const* OfficeBlock::ExecutiveGradeTooLowExecption::what() const throw()
{
	return "executive grade too low.";
}

OfficeBlock::OfficeBlock()
	:	intern_(NULL),
		signatory_(NULL),
		executive_(NULL)
{
	return;
}

OfficeBlock::OfficeBlock(Intern* intern, Bureaucrat* signatory,
			Bureaucrat* executive)
	:	intern_(intern),
		signatory_(signatory),
		executive_(executive)
{
	return;
}

void OfficeBlock::setIntern(Intern* intern)
{
	this->intern_ = intern;
	return;
}

void OfficeBlock::setSignatory(Bureaucrat* signatory)
{
	this->signatory_ = signatory;
	return;
}

void OfficeBlock::setExecutive(Bureaucrat* executive)
{
	this->executive_ = executive;
	return;
}

void OfficeBlock::doBureaucracy(const std::string &form_name,
		std::string target) const
{
	if (this->intern_ == NULL || this->signatory_ == NULL
			|| this->executive_ == NULL) {
		throw OfficeBlock::OfficeBlockIsntFilledException();
	}
	Form* form = this->intern_->makeForm(form_name, target);
	if (form == NULL) {
		throw OfficeBlock::UnknownFormNameException();
	}
	else if (this->signatory_->signForm(*form) == false) {
		delete form;
		throw OfficeBlock::SignatoryGradeTooLowExecption();
	}
	else if (this->executive_->executeForm(*form) == false) {
		delete form;
		throw OfficeBlock::ExecutiveGradeTooLowExecption();
	}
	delete form;
}
