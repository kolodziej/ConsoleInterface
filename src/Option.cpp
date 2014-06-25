#include <string>
#include "Option.hpp"
#include "Exception.hpp"

using namespace CI;

void Option::SetShortName(char _shortName)
{
	// validate a-zA-Z
	if ((_shortName >= 'a' && _shortName <= 'z') || (_shortName >= 'A' && _shortName <= 'Z'))
		shortName = _shortName;
	else
		throw Exception_InvalidOptionName;
}

void Option::SetLongName(std::string & _longName)
{
	if (_ValidateLongName(_longName))
		longName = _longName;
	else
		throw Exception_InvalidOptionName;
}

void Option::SetValue(std::string & _value)
{
	if (hasValue)
		value = _value;
	else
		throw Exception_OptionHasNotValue;
}

bool Option::_ValidateLongName(std::string & _value)
{
	char fc = _value[0];
	if ((fc >= 'A' && fc <= 'Z') || (fc >= 'a' && fc <= 'z'))
	{
		for (std::string::iterator it = _value.begin() + 1; it != _value.end(); ++it)
		{
			if (!(((*it) >= '0' && (*it) <= '9') || ((*it) >= 'A' && (*it) <= 'Z') || ((*it) >= 'a' && (*it) <= 'z')))
				return false;
		}
	} else
	{
		return false;
	}

	return true;
}
