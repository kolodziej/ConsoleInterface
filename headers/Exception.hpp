#ifndef CI_EXCEPTION_HPP
#define CI_EXCEPTION_HPP
#include <stdexcept>
#include <string>
#include <memory>

namespace CI
{
	struct Exception : std::exception
	{
		~Exception() noexcept {};	
		virtual const char * what() const noexcept;
	};

	typedef std::shared_ptr<Exception> ExceptionPtr;

	struct OptionException : Exception
	{
		std::string option;
		OptionException(std::string);
		OptionException(char);
		virtual const char * what() const noexcept = 0;
	};

	typedef std::shared_ptr<OptionException> OptionExceptionPtr;

	struct Exception_OptionNotExists : OptionException
	{
		Exception_OptionNotExists(std::string _longName) : OptionException(_longName) {};
		Exception_OptionNotExists(char _shortName) : OptionException(_shortName) {};
		virtual const char * what() const noexcept;
	};

	struct Exception_InvalidOptionName : OptionException
	{
		Exception_InvalidOptionName(std::string _longName) : OptionException(_longName) {};
		Exception_InvalidOptionName(char _shortName) : OptionException(_shortName) {};
		virtual const char * what() const noexcept;
	};

	struct Exception_OptionHasNotValue : OptionException
	{
		Exception_OptionHasNotValue(std::string _longName) : OptionException(_longName) {};
		Exception_OptionHasNotValue(char _shortName) : OptionException(_shortName) {};
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

	struct Exception_OptionIsSet : OptionException
	{
		Exception_OptionIsSet(char _shortName) : OptionException(_shortName) {}
		Exception_OptionIsSet(std::string _longName) : OptionException(_longName) {}
		virtual const char * what() const noexcept;
	};

	struct Exception_OptionNotMultiValue : OptionException
	{
		Exception_OptionNotMultiValue(char _shortName) : OptionException(_shortName) {}
		Exception_OptionNotMultiValue(std::string _longName) : OptionException(_longName) {}
		virtual const char * what() const noexcept;
	};
}

#endif
