#include <string>
#include "Option.hpp"
#include "Exception.hpp"

using namespace CI;

void Option::SetShortName(char _shortName) throw(OptionExceptionPtr)
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
		throw OptionExceptionPtr(new Exception_InvalidOptionName(_shortName));
}

void Option::SetLongName(std::string & _longName) throw(OptionExceptionPtr)
{
	if (_longName.empty())
	{
		longName = _longName;
		return;
	}
	if (_ValidateLongName(_longName))
		longName = _longName;
	else
		throw OptionExceptionPtr(new Exception_InvalidOptionName(_longName));
}

void Option::SetHasValue(bool _hasValue)
{
	hasValue = _hasValue;
}

void Option::SetAllowMultiValue(bool _allowMultiValue)
{
	if (_allowMultiValue)
		SetHasValue(true);

	allowMultiValue = _allowMultiValue;
}

void Option::Set(bool _set)
{
	isset = _set;
}

void Option::SetValue(std::string & _value) throw(OptionExceptionPtr)
{
	if (hasValue)
		*(values.begin()) = _value;
	else
		throw OptionExceptionPtr(new Exception_OptionHasNotValue(longName));
}

void Option::AddValue(std::string & _value) throw(OptionExceptionPtr)
{
	if (allowMultiValue)
		values.push_back(_value);
	else
		throw OptionExceptionPtr(new Exception_OptionNotMultiValue(longName));
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

bool Option::IsAllowedMultiValue() const
{
	return allowMultiValue;
}

std::string Option::GetValue(std::string _default) throw(OptionExceptionPtr)
{
	if (hasValue)
	{
		if (values.empty())
			return _default;
		else
			return *(values.begin());
	}
	else
	{
		if (shortName != 0)
			throw OptionExceptionPtr(new Exception_OptionHasNotValue(shortName));
		else
			throw OptionExceptionPtr(new Exception_OptionHasNotValue(longName));
	}
}

std::vector<std::string> Option::GetValues() throw(OptionExceptionPtr)
{
	if (allowMultiValue)
		return values;
	else
		throw OptionExceptionPtr(new Exception_OptionNotMultiValue(longName));
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
