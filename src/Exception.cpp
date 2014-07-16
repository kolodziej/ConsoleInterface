#include "Exception.hpp"
#include <sstream>
#include <string>

using namespace CI;

const char * Exception::what() const throw()
{
	return "CI: An undefined error occurred!";
}

Exception_OptionNotExists::Exception_OptionNotExists(std::string  _longName)
{
	std::stringstream str;
	str << "CI: Option --" << _longName << " does not exist!\n";
	getline(str, error);
}

Exception_OptionNotExists::Exception_OptionNotExists(char _shortName)
{
	std::stringstream str;
	str << "CI: Option -" << _shortName << " does not exist!\n";
	getline(str, error);
}

const char * Exception_OptionNotExists::what() const throw()
{
	return error.c_str();
}

Exception_InvalidOptionName::Exception_InvalidOptionName(std::string _longName)
{
	std::stringstream str;
	str << "CI: --" << _longName << " is invalid option name! Check valid options' names in README.md.\n";
	getline(str, error);
}

Exception_InvalidOptionName::Exception_InvalidOptionName(char _shortName)
{
	std::stringstream str;
	str << "CI: -" << _shortName << " is invalid option name! Check valid options' names in README.md.\n";
	getline(str, error);
}

const char * Exception_InvalidOptionName::what() const throw()
{
	return error.c_str();
}

Exception_OptionHasNotValue::Exception_OptionHasNotValue(std::string & _longName)
{
	std::stringstream str;
	str << "CI: --" << _longName << " cannot have a value\n";
	getline(str, error);
}

Exception_OptionHasNotValue::Exception_OptionHasNotValue(char _shortName)
{
	std::stringstream str;
	str << "CI: -" << _shortName << " cannot have a value\n";
	getline(str, error);
}

const char * Exception_OptionHasNotValue::what() const throw()
{
	return error.c_str();
}

const char * Exception_NoArguments::what() const throw()
{
	return "CI: Using arguments is not allowed!";
}

const char * Exception_ValuesRequired::what() const throw()
{
	return "CI: Not all options which get value have them!";
}
