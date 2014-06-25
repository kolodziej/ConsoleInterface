#ifndef CI_EXCEPTION_HPP
#define CI_EXCEPTION_HPP
#include "Option.hpp"
#include <exception>
#include <string>
#include <stringstream>

namespace CI
{
	struct Exception : std::exception
	{
		virtual const char * what() const throw()
		{
			return "CI: An error occurred!";
		}
	};

	struct Exception_OptionNotExists : Exception
	{
		virtual const char * what() const throw()
		{
			return "CI: Option doesn't exist!";
		}
	};

	struct Exception_InvalidOptionName : Exception
	{
		virtual const char * what() const throw()
		{
			return "CI: Invalid option name!";
		}
	};

	struct Exception_OptionHasNotValue : Exception
	{
		virtual const char * what() const throw()
		{
			return "CI: Option has not a value!";
		}
	};
}

#endif
