#include "ConsoleInterface.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

ConsoleInterface::ConsoleInterface(int argc, char ** argv) : _argc(argc), _argv(argv)
{}

ConsoleInterface::~ConsoleInterface()
{
	for (auto it = _options.begin(); it != _options.end(); ++it)
	{
		delete (*it);
	}
}

bool ConsoleInterface::IsOption(const char * optionName)
{
	try {
		auto it = _search(optionName);
		return (*it)->isSet;
	} catch (ConsoleInterfaceException_OptionNotExists &exc)
	{
		return false;
	}
}

void ConsoleInterface::AddOption(const char * optionName, bool hasValue)
{
	option * p = new option(optionName, hasValue);
	_options.push_back(p);
}

ConsoleInterface::option * ConsoleInterface::GetOption(const char * optionName)
{
	try {
		auto it = _search(optionName);
		return (*it);
	} catch (ConsoleInterfaceException_OptionNotExists &exc)
	{
		return NULL;
	}
}

void ConsoleInterface::Process()
{
	for (int i = 1; i < _argc; ++i)
	{
		char * equalCharPosition = strchr(_argv[i], '=');
		char * optName;
		char * value = NULL;
		if (equalCharPosition != NULL)
		{
			int n = equalCharPosition - _argv[i];
			optName = new char[n+1];
			strncpy(optName, _argv[i], n);
			optName[n] = '\0';
			value = _argv[i] + n + 1;
		} else
		{
			optName = _argv[i];
		}

		try {
			auto it = _search(optName);
			(*it)->isSet = true;
			if ((*it)->hasValue && value != NULL)
			{
				(*it)->value = value;
			} else if ((*it)->hasValue)
			{
				if (i+1 < _argc)
					(*it)->value = _argv[++i];
			}
		} catch (ConsoleInterfaceException_OptionNotExists &exc)
		{
			_arguments.push_back(_argv[i]);
		}
	}
}

std::vector<ConsoleInterface::option*>::iterator ConsoleInterface::_search(const char * optionName) throw(ConsoleInterfaceException_OptionNotExists)
{
	for (auto it = _options.begin(); it != _options.end(); ++it)
	{
		if (*(*it) == optionName)
			return it;
	}

	throw ConsoleInterfaceException_OptionNotExists();
}

