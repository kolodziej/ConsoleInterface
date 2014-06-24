#include <iostream>
#include <string>
#include "ConsoleInterface.hpp"

using namespace std;
using namespace CI;

int main(int argc, char ** argv)
{
	Application app(argc, argv);
	app.AddOption('v', "version", false);
	app.AddOption(0, "compile", false);
	app.AddOption('a', "archive", true);
	app.AddOption('f', "file", true);
	app.Process();
	for (auto it = app.GetOptions().begin(); it != app.GetOptions().end(); ++it)
	{
		cout << (*it)->shortName << " == " << (*it)->longName << " (" << static_cast<int>((*it)->isset) << ")";
		if ((*it)->hasValue)
			cout << " value: " << (*it)->value;

		cout << "\n";
	}
	return 0;
}
