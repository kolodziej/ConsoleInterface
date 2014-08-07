#ifndef CI_OPTION_HPP
#define CI_OPTION_HPP
#include "Exception.hpp"
#include <string>

namespace CI
{
	class Option
	{
		private:
			char shortName;
			std::string longName;
			bool isset;
			bool hasValue;
			std::string value;

		public:
			Option() :
				shortName(0),
				isset(false),
				hasValue(false)
			{}

			void SetShortName(char) throw(OptionExceptionPtr);
			void SetLongName(std::string &) throw(OptionExceptionPtr);
			void SetHasValue(bool = true);
			void Set(bool = true);
			void SetValue(std::string &) throw(OptionExceptionPtr);

			char GetShortName() const;
			std::string & GetLongName();
			bool Isset() const;
			bool HasValue() const;
			std::string GetValue(std::string = std::string()) throw(OptionExceptionPtr);

		private:
			bool _ValidateLongName(std::string &);
	};
}

#endif
