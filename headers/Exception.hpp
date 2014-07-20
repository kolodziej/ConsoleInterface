#ifndef CI_EXCEPTION_HPP
#define CI_EXCEPTION_HPP
#include <stdexcept>
#include <string>
#include <sstream>

namespace CI
{
	struct Exception : std::exception
	{
		~Exception() noexcept {};	
		virtual const char * what() const noexcept;
	};

	struct Exception_OptionNotExists : Exception
	{
		std::string error;
		Exception_OptionNotExists(std::string);
		Exception_OptionNotExists(char);
		virtual const char * what() const noexcept;
	};

	struct Exception_InvalidOptionName : Exception
	{
		std::string error;
		Exception_InvalidOptionName(std::string);
		Exception_InvalidOptionName(char);
		virtual const char * what() const noexcept;
	};

	struct Exception_OptionHasNotValue : Exception
	{
		std::string error;
		Exception_OptionHasNotValue(std::string &);
		Exception_OptionHasNotValue(char);
		virtual const char * what() const noexcept;
	};

	struct Exception_NoArguments : Exception
	{
		virtual const char * what() const noexcept;
	};

	struct Exception_ValuesRequired : Exception
	{
		virtual const char * what() const noexcept;
	};
}

#endif
