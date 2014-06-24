#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ConsoleInterface.hpp"

using namespace std;
using namespace CI;

ostream & operator<<(ostream & stream, const Option * opt)
{
	stream << setw(14) << "short name: ";
	if (opt->shortName == 0)
		cout << "[none]\n";
	else
		cout << opt->shortName << "\n";

	stream << setw(14) << "long name: ";
	if (opt->longName.empty())
		cout << "[none]\n";
	else
		cout << opt->longName << "\n";

	stream << setw(14) << "is set? ";
	if (opt->isset)
		stream << "yes\n";
	else
		stream << "no\n";

	stream << setw(14) << "has value? ";
	if (opt->hasValue)
	{
		stream << "yes: ";
		if (opt->value.empty())
			stream << "[not set]\n";
		else
			stream << opt->value << "\n";

	} else
	{
		stream << "no\n";
	}
	stream << "--------------------\n";

	return stream;
}

int main(int argc, char ** argv)
{
	Application app(argc, argv);
	int n;
	char s;
	Option * opt;
	cout << "Type number of options: ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		opt = new Option;
		cout << "Type \e[1ma letter\e[0m symbolising short option: ";
		cin >> opt->shortName;
		cout << "Type long name of this option: ";
		cin >> opt->longName;
		cout << "Does this option have a value? [y/n] ";
		do {
			cin >> s;
			if (s != 'y' && s != 'n')
				cout << "wrong letter! type y or n!\n";
		} while (s != 'y' && s != 'n');
		if (s == 'y')
			opt->hasValue = true;
		else
			opt->hasValue = false;

		cout << "==========\n";
		app.AddOption(opt);
	}

	// processing all arguments and values passed in argv
	app.Process();

	for (auto it = app.GetOptions().begin(); it != app.GetOptions().end(); ++it)
	{
		cout << (*it);
	}
	return 0;
}
