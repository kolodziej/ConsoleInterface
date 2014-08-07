#include "Application.hpp"
#include "Option.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>
#include <cstring>

using namespace CI;

Application::Application(int _argc, char ** _argv, unsigned int _settings) :
	argc(_argc),
	argv(_argv),
	value_queue(NULL),
	queue_b(0),
	queue_e(0),
	settings(_settings)
{
	for (int i = 1; i < argc; argv_params.push_back(std::string(argv[i++])));	
}

Application::~Application()
{}

void Application::AddOption(Option * _opt) throw(Exception_InvalidOptionName)
{
	options.push_back(_opt);
}

void Application::AddOption(char _shortName, std::string _longName, bool _hasValue) throw(Exception_InvalidOptionName)
{
	Option * opt = new Option;
	opt->SetShortName(_shortName);
	opt->SetLongName(_longName);
	opt->SetHasValue(_hasValue);
	AddOption(opt);
}

bool Application::IsOptionSet(char _shortName)
{
	Option * opt = _SearchOption(_shortName);
	return opt->Isset();
}

bool Application::IsOptionSet(std::string & _longName)
{
	Option * opt = _SearchOption(_longName);
	return opt->Isset();
}

std::string Application::GetOptionValue(char _shortName, std::string _default) throw(Exception_OptionHasNotValue)
{
	Option * opt = _SearchOption(_shortName);
	return opt->GetValue(_default);
}

std::string Application::GetOptionValue(std::string _longName, std::string _default) throw(Exception_OptionHasNotValue)
{
	Option * opt = _SearchOption(_longName);
	return opt->GetValue(_default);
}

std::vector<Option*> & Application::GetOptions()
{
	return options;
}

std::vector<std::string> & Application::GetArguments()
{
	return arguments;
}

void Application::Process() throw(Exception, Exception_OptionNotExists, Exception_InvalidOptionName, Exception_OptionHasNotValue)
{
	value_queue = new Option*[options.size()];
	for (int i = 1; i < argc; ++i)
	{
		const char *arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-')
		{
			_ProcessLong(arg+2);
		} else if (arg[0] == '-')
		{
			_ProcessShort(arg+1);
		} else
		{
			_ProcessValue(arg);
		}
	}
	if (queue_b < queue_e && _CheckSettings(RequireValue))
	{
		throw Exception_ValuesRequired();
	}
	delete [] value_queue;
}

void Application::_ProcessShort(const char * _str)
{
	size_t len = strlen(_str);
	if (len == 1)
	{
		_ProcessOption(_str[0]);
	} else
	{
		for (int i = 0; i < len; _ProcessOption(_str[i++]));
	}
}

void Application::_ProcessLong(const char * _str)
{
	size_t len = strlen(_str);
	std::string option(_str, len);
	_ProcessOption(option);
}

bool Application::_ProcessOption(char _shortName)
{
	Option * opt = _SearchOption(_shortName);
	// value
	if (opt->HasValue())
		value_queue[queue_e++] = opt;

	// call Option handler
	opt->Set();

	return true;
}

bool Application::_ProcessOption(std::string _longName)
{
	Option * opt = _SearchOption(_longName);
	// value
	if (opt->HasValue())
		value_queue[queue_e++] = opt;

	// call Option handler
	opt->Set();

	return true;
}

void Application::_ProcessValue(const char * _val)
{
	if (queue_b < queue_e)
	{
		std::string value(_val);
		(value_queue[queue_b++])->SetValue(value);
	} else if (_CheckSettings(NoArguments))
	{
		throw Exception_NoArguments();
	} else
	{
		_ProcessArgument(_val);
	}
}

void Application::_ProcessArgument(const char * _val)
{
	std::string arg(_val);
	arguments.push_back(arg);
}

bool Application::_CheckSettings(Settings _set)
{
	return static_cast<bool>(settings & _set);
}

Option * Application::_SearchOption(char _shortName) throw(Exception_OptionNotExists)
{
	auto it = options.begin();
	while (it != options.end() && (*it)->GetShortName() != _shortName)
		++it;

	if (it == options.end())
		throw Exception_OptionNotExists(_shortName);

	return (*it);
}

Option * Application::_SearchOption(std::string & _longName) throw(Exception_OptionNotExists)
{
	auto it = options.begin();
	while (it != options.end() && (*it)->GetLongName() != _longName)
		++it;

	if (it == options.end())
		throw Exception_OptionNotExists(_longName);

	return (*it);
}
