#include "Exception.hpp"
#include <string>
#include <memory>

using namespace CI;

const char * Exception::what() const throw()
{
	return "CI: An undefined error occurred!\n";
}

OptionException::OptionException(std::string _longName)
{
	option = std::string("--") + _longName;
}

OptionException::OptionException(char _shortName)
{
	option = std::string("-") + _shortName;
}

const char * Exception_OptionNotExists::what() const noexcept
{
	std::string error = "CI: Option " + option + " does not exist!\n";
	return error.data();
}

const char * Exception_InvalidOptionName::what() const throw()
{
	std::string error = "CI: " + option + " is invalid option name! Check naming rules in README.md\n";
	return error.data();
}

const char * Exception_OptionHasNotValue::what() const throw()
{
	std::string error = "CI: Option " + option + " cannot have a value!\n";
	return error.data();
}

const char * Exception_NoArguments::what() const throw()
{
	return "CI: Using arguments is not allowed!\n";
}

const char * Exception_ValuesRequired::what() const throw()
{
	return "CI: Not all options which get value have them!\n";
}

const char * Exception_OptionIsSet::what() const noexcept
{
	std::string error = "CI: Option " + option + " has already been set!\n";
	return error.data();
}
