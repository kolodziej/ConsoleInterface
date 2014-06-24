#include "Application.hpp"
#include "Option.hpp"
#include <string>
#include <vector>
#include <cstring>

using namespace CI;

Application::Application(int _argc, char ** _argv) :
	argc(_argc),
	argv(_argv),
	value_queue(new Option*[_argc]),
	queue_b(0),
	queue_e(0)
{}

Application::~Application()
{}

void Application::AddOption(Option * _opt)
{
	options.push_back(_opt);
}

void Application::AddOption(char _shortName, std::string _longName, bool _hasValue)
{
	Option * opt = new Option;
	opt->shortName = _shortName;
	opt->longName = _longName;
	opt->hasValue = _hasValue;
	AddOption(opt);
}

std::vector<Option*> & Application::GetOptions()
{
	return options;
}

void Application::Process()
{
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

bool Application::_ProcessOption(char _arg)
{
	auto it = options.begin();
	while ((*it)->shortName != _arg && it != options.end())
		++it;

	if (it == options.end())
		return false;

	// value
	if ((*it)->hasValue)
		value_queue[queue_e++] = (*it);

	// call Option handler
	(*it)->isset = true;

	return true;
}

bool Application::_ProcessOption(std::string _arg)
{
	auto it = options.begin();
	while ((*it)->longName != _arg && it != options.end())
		++it;

	if (it == options.end())
		return false;

	// value
	if ((*it)->hasValue)
		value_queue[queue_e++] = (*it);

	// call Option handler
	(*it)->isset = true;

	return true;
}

bool Application::_ProcessValue(const char * _val)
{
	size_t len = strlen(_val);
	(value_queue[queue_b++])->value = std::string(_val,len);
	return true;
}
