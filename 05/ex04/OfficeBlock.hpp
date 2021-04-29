#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <exception>
#include <string>

class Intern;
class Bureaucrat;

class OfficeBlock
{
public:
	class OfficeBlockIsntFilledException : public std::exception
	{
	public:
		virtual char const* what() const throw();
	};
	class UnknownFormNameException : public std::exception
	{
	public:
		virtual char const* what() const throw();
	};
	class SignatoryGradeTooLowExecption : public std::exception
	{
	public:
		virtual char const* what() const throw();
	};
	class ExecutiveGradeTooLowExecption : public std::exception
	{
	public:
		virtual char const* what() const throw();
	};
	OfficeBlock();
	OfficeBlock(Intern* intern, Bureaucrat* signatory,
			Bureaucrat* executive);

	void setIntern(Intern* intern);
	void setSignatory(Bureaucrat* signatory);
	void setExecutive(Bureaucrat* executive);

	void doBureaucracy(std::string const& form_name, std::string target) const;

private:
	Intern* intern_;
	Bureaucrat* signatory_;
	Bureaucrat* executive_;
};

#endif
