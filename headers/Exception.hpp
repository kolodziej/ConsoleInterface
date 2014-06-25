#ifndef CI_EXCEPTION_HPP
#define CI_EXCEPTION_HPP
#include "Option.hpp"
#include <exception>

namespace CI
{
	struct Exception : std::exception
	{
		enum Code
		{
			OPTION_NOT_EXISTS = 404,
			INVALID_OPTION_NAME,
			OPTION_HAS_NOT_VALUE,
		};
		Code code;
		Exception(Code _code) : code(_code) {}
	};
}

#endif
