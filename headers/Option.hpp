#ifndef CI_OPTION_HPP
#define CI_OPTION_HPP
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

			void SetShortName(char);
			void SetLongName(std::string &);
			void SetHasValue(bool _hasValue)
			{
				hasValue = _hasValue;
			}
			void Set()
			{
				isset = true;
			}
			void Unset()
			{
				isset = false;
			}
			void SetValue(std::string &);

			char GetShortName()
			{
				return shortName;
			}
			std::string & GetLongName()
			{
				return longName;
			}
			bool Isset() const
			{
				return isset;
			}
			bool HasValue() const
			{
				return hasValue;
			}
			std::string & GetValue()
			{
				return value;
			}

		private:
			bool _ValidateLongName(std::string &);
	};
}

#endif
