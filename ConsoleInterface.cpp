#include "ConsoleInterface.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

ConsoleInterface::ConsoleInterface(int argc, char ** argv) : _argc(argc), _argv(argv)
{}

ConsoleInterface::~ConsoleInterface()
{
	for (std::vector<ConsoleInterface::param*>::iterator it = _params.begin(); it != _params.end(); ++it)
	{
		delete (*it);
	}
}

bool ConsoleInterface::IsParam(const char * paramName)
{
	std::vector<ConsoleInterface::param*>::iterator it = _searchByName(paramName);
	if (it != _params.end())
		return true;
	
	return false;
}

void ConsoleInterface::AddParam(const char * paramName, bool paramUseDash)
{
	param * p = new param(paramName, paramUseDash);
	_params.push_back(p);
}

char * ConsoleInterface::GetParamValue(const char * paramName)
{
	auto it = _searchByName(paramName);
	return (*it)->value;
}

ConsoleInterface::param * ConsoleInterface::GetParam(size_t index)
{
	if (index < _params.size())
		return _params.at(index);
	else
		return NULL;
}

ConsoleInterface::param * ConsoleInterface::GetParam(const char * paramName)
{
	auto it = _searchByName(paramName);
	if (it != _params.end())
		return (*it);
	else
		return NULL;
}

void ConsoleInterface::Process()
{
	for (int i = 1; i < _argc; ++i)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			try {
				auto it = _searchByName(argv[i]+2);
				ProcessLongParam(i);
			} catch (ConsoleInterfaceException_ParamNotExists &exc)
			{
				cout << exc.write() << ": " << argv[i] << endl;
			}
		} else if (argv[i][0] == '-')
		{
			try {
				auto it = _searchByName(argv[i]+1);
				ProcessShortParam(i);
			} catch (ConsoleInterfaceException_ParamNotExists &exc)
			{
				cout << exc.write() << ": " << argv[i] << endl;
			}
		} else
		{
			try {

		}
	}
}

std::vector<ConsoleInterface::param*>::iterator ConsoleInterface::_searchByName(const char * paramName)
{
	auto it = _params.begin();
	while (it != _params.end() && strcmp(paramName,(*it)->name) != 0)
	{
		++it;
	}
	if (it == _params.end())
		throw ConsoleInterfaceException_ParamNotExists;

	return it;
}
