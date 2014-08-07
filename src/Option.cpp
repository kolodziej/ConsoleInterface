#include <string>
#include "Option.hpp"
#include "Exception.hpp"

using namespace CI;

void Option::SetShortName(char _shortName) throw(Exception_InvalidOptionName)
{
	if (_shortName == 0)
	{
		_shortName = 0;
		return;
	}
	// validate a-zA-Z
	if ((_shortName >= 'a' && _shortName <= 'z') || (_shortName >= 'A' && _shortName <= 'Z'))
		shortName = _shortName;
	else
		throw Exception_InvalidOptionName(_shortName);
}

void Option::SetLongName(std::string & _longName) throw(Exception_InvalidOptionName)
{
	if (_longName.empty())
	{
		longName = _longName;
		return;
	}
	if (_ValidateLongName(_longName))
		longName = _longName;
	else
		throw Exception_InvalidOptionName(_longName);
}

void Option::SetHasValue(bool _hasValue)
{
	hasValue = _hasValue;
}

void Option::Set(bool _set)
{
	isset = _set;
}

void Option::SetValue(std::string & _value) throw(Exception_OptionHasNotValue)
{
	if (hasValue)
		value = _value;
	else
		throw Exception_OptionHasNotValue(longName);
}

char Option::GetShortName() const
{
	return shortName;
}

std::string & Option::GetLongName()
{
	return longName;
}

bool Option::Isset() const
{
	return isset;
}

bool Option::HasValue() const
{
	return hasValue;
}

std::string Option::GetValue(std::string _default) throw(Exception_OptionHasNotValue)
{
	if (hasValue)
	{
		if (value.empty())
			return _default;
		else
			return value;
	}
	else
	{
		if (shortName != 0)
			throw Exception_OptionHasNotValue(shortName);
		else
			throw Exception_OptionHasNotValue(longName);
	}
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
