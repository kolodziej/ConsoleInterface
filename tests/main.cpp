#include <iostream>
#include "ConsoleInterface.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	ConsoleInterface app(argc, argv);
	app.AddOption("-v");
	app.AddOption("--version");
	app.AddOption("--number",true);
	app.Process();
	cout << "-v: " << (int)app.IsOption("-v") << "\n--version: " << (int)app.IsOption("--version") << "\n--number: " << (int)app.IsOption("--number") << "\n";
	if (app.IsOption("--number") && app.GetOption("--number")->value != NULL)
		cout << "Number: " << app.GetOption("--number")->value << "\n";
	return 0;
}
