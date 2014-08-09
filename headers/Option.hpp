#ifndef CI_OPTION_HPP
#define CI_OPTION_HPP
#include "Exception.hpp"
#include <string>
#include <vector>

namespace CI
{
	class Option
	{
		private:
			char shortName;
			std::string longName;
			bool isset;
			bool hasValue;
			bool allowMultiValue;
			std::vector<std::string> values;

		public:
			Option() :
				shortName(0),
				isset(false),
				hasValue(false),
				allowMultiValue(false)
			{}

			Option(char _shortName, std::string & _longName, bool _hasValue, bool _allowMultiValue = false) :
				shortName(_shortName),
				longName(_longName),
				hasValue(_hasValue),
				allowMultiValue(_allowMultiValue)
			{}

			void SetShortName(char) throw(OptionExceptionPtr);
			void SetLongName(std::string &) throw(OptionExceptionPtr);
			void SetHasValue(bool = true);
			void SetAllowMultiValue(bool = true);
			void Set(bool = true);
			void SetValue(std::string &) throw(OptionExceptionPtr);
			void AddValue(std::string &) throw(OptionExceptionPtr);

			char GetShortName() const;
			std::string & GetLongName();
			bool Isset() const;
			bool HasValue() const;
			bool IsAllowedMultiValue() const;
			std::string GetValue(std::string = std::string()) throw(OptionExceptionPtr);
			std::vector<std::string> GetValues() throw(OptionExceptionPtr);

		private:
			bool _ValidateLongName(std::string &);
	};
}

#endif
