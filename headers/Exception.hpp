#ifndef CI_EXCEPTION_HPP
#define CI_EXCEPTION_HPP
#include "Option.hpp"
#include <exception>
#include <string>
#include <sstream>

namespace CI
{
	struct Exception : std::exception
	{
		virtual const char * what() const throw()
		{
			return "CI: An undefined error occurred!";
		}
	};

	struct Exception_OptionNotExists : Exception
	{
		std::string error;
		Exception_OptionNotExists(std::string & _longName)
		{
			std::stringstream str;
			str << "CI: Option --" << _longName << " does not exist!\n";
			getline(str, error);
		}
		Exception_OptionNotExists(char _shortName)
		{
			std::stringstream str;
			str << "CI: Option -" << _shortName << " does not exist!\n";
			getline(str, error);
		}
		virtual const char * what() const throw()
		{
			return error.c_str();
		}
	};

	struct Exception_InvalidOptionName : Exception
	{
		std::string error;
		Exception_InvalidOptionName(std::string & _longName)
		{
			std::stringstream str;
			str << "CI: --" << _longName << " is invalid option name! Check valid options' names in README.md.\n";
			getline(str, error);
		}
		Exception_InvalidOptionName(char _shortName)
		{
			std::stringstream str;
			str << "CI: -" << _shortName << " is invalid option name! Check valid options' names in README.md.\n";
			getline(str, error);
		}
		virtual const char * what() const throw()
		{
			return error.c_str();
		}
	};

	struct Exception_OptionHasNotValue : Exception
	{
		std::string error;
		Exception_OptionHasNotValue(std::string & _longName)
		{
			std::stringstream str;
			str << "CI: --" << _longName << " cannot have a value\n";
			getline(str, error);
		}
		Exception_OptionHasNotValue(char _shortName)
		{
			std::stringstream str;
			str << "CI: -" << _shortName << " cannot have a value\n";
			getline(str, error);
		}
		virtual const char * what() const throw()
		{
			return error.c_str();
		}
	};
}

#endif
