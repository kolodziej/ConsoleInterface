#ifndef CI_OPTION_HPP
#define CI_OPTION_HPP
#include <string>

namespace CI
{
	struct Option
	{
		char shortName;
		std::string longName;
		bool isset;
		bool hasValue;
		std::string value;

		Option() :
			shortName(0),
			isset(false),
			hasValue(false)
		{}
	};
}

#endif
