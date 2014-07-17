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

			void SetShortName(char) throw(Exception_InvalidOptionName);
			void SetLongName(std::string &) throw(Exception_InvalidOptionName);
			void SetHasValue(bool = true);
			void Set(bool = true);
			void SetValue(std::string &) throw(Exception_OptionHasNotValue);

			char GetShortName() const;
			std::string & GetLongName();
			bool Isset() const;
			bool HasValue() const;
			std::string & GetValue() throw(Exception_OptionHasNotValue);

		private:
			bool _ValidateLongName(std::string &);
	};
}

#endif
