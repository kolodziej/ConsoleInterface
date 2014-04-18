ConsoleInterface
================

Console Interface is a simple class which provides a bunch of simple tools for C++ console applications.
ConsoleInterface interprets startup arguments passed using __char \*\* argv__.

You can define your options in `ConsoleInterface` class instance and run Process() method. Then you can check which options has been passed to application and what were they values (if they were).

Getting started
---------------

What do you have to do to use `ConsoleInterface`?

1. Create an instance of `ConsoleInterface`. The constructor takes `int argc` and `char ** argv` variables.
2. Add your options and define which of them can have value.
3. Run `Process` method.
4. Use `ConsoleInterface` functions like: `IsOption`, `GetOption` etc.

Sample:
	
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
