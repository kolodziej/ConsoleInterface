#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include "ConsoleInterface.hpp"

using namespace std;
using namespace CI;

ostream & operator<<(ostream & stream, std::shared_ptr<Option> opt)
{
	stream << setw(14) << "short name: ";
	if (opt->GetShortName() == 0)
		cout << "\e[2m[none]\e[0m\n";
	else
		cout << opt->GetShortName() << "\n";

	stream << setw(14) << "long name: ";
	if (opt->GetLongName().empty())
		cout << "\e[2m[none]\e[0m\n";
	else
		cout << opt->GetLongName() << "\n";

	stream << setw(14) << "is set? ";
	if (opt->Isset())
		stream << "\e[1;32myes\e[0m\n";
	else
		stream << "\e[1;31mno\e[0m\n";

	stream << setw(14) << "has value? ";
	if (opt->HasValue())
	{
		stream << "\e[1;32myes\e[0m: ";
		if (opt->GetValue().empty())
			stream << "\e[2m[not set]\e[0m\n";
		else
		{
			if (opt->IsAllowedMultiValue())
			{
				for (auto v : opt->GetValues())
					stream << v << ", ";
			} else
				stream << opt->GetValue();

			stream << "\n";
		}

	} else
	{
		stream << "\e[1;31mno\e[0m\n";
	}
	stream << "--------------------\n";

	return stream;
}

int main(int argc, char ** argv)
{
	Application app(argc, argv, Application::RequireValue);
	cout << "Using ConsoleInterface " << CI::Version::StringVersion() << endl;
	fstream f("dataset", ios::in);
	if (!f)
	{
		cerr << "Error while opening `dataset' file which contains rules!\n";
		return 1;
	}
	char shortName;
	string longName;
	char hasValue;
	char boolHasValue;
	try {
		int num;
		f >> num;
		for (int i = 0; i < num; ++i)
		{
			f >> shortName >> longName >> hasValue;
			if (shortName == '0')
				shortName = 0;

			if (hasValue == 'y')
				boolHasValue = true;
			else
				boolHasValue = false;

			app.AddOption(shortName, longName, boolHasValue);
		}
		app.AddOption('I', std::string(), true, true);
	} catch (Exception_InvalidOptionName &e)
	{
		cerr << e.what() << "\n";
		return 1;
	}

	// processing all arguments and values passed in argv
	try {
		app.Process();
	} catch (ExceptionPtr e)
	{
		cerr << e->what();
		return 1;
	} catch (OptionExceptionPtr e)
	{
		cerr << e->what();
		return 1;
	} catch (std::out_of_range &e)
	{
		cerr << e.what();
		return 1;
	}

	for (auto it = app.GetOptions().begin(); it != app.GetOptions().end(); ++it)
	{
		cout << (*it);
	}

	auto val = app.GetOptionValue("archive", "[default archive]");
	cout << "With default value: " << val << "\n";

	// arguments
	cout << "Arguments: \n\e[1;32m";
	if (app.GetArguments().size() == 0)
	{
		cout << "\e[1;31mthere are no arguments\n";
	}
	for (auto it = app.GetArguments().begin(); it != app.GetArguments().end(); ++it)
	{
		cout << "\t" << (*it) << "\n";
	}
	cout << "\e[0m";
	return 0;
}
