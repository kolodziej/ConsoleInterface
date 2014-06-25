ConsoleInterface
================

Console Interface is a simple framework which provides an interface for our applications which use startup params (command line arguments). ConsoleInterface interprets startup arguments passed using __char \*\* argv__.

You can define your options in `ConsoleInterface` class instance and run `Process()` method. Then you can check which options has been passed to application and what were they values (if they were).

__Framework is in alpha version! It will gain some very interesting and important features!__

Getting started
---------------

What do you have to do to use `ConsoleInterface`?

1. Create an instance of `ConsoleInterface`. The constructor takes `int argc` and `char \*\* argv` variables.
2. Add your options and define which of them can have value using `AddOption` method.
3. Run `Process` method. `Process` method throws some exceptions: `Exception_OptionNotExists` (when there is no option with such short name or long name), `Excpetion_InvalidOptionName` (when you try to set invalid option name; short name must be a letter a-z or A-Z; long name must starts with a letter, then you can use letters and numbers), `Exception_OptionHasNotValue` (when you try to get value of option which doesn't have a value)
4. To check if option is set or get its value you can use `Application::IsOptionSet` or `Option::Isset` methods.
5. To get option's value you will use these methods: `Application::GetOptionValue` and `Option::GetValue`.

Samples
-------

You can check sample application which use `ConsoleInterface` in `tests` directory. To compile whole project you should use Makefiles. Running these commands will allow you to test library.

	make all
	cd tests
	make all
	./ConsoleInterfaceTest --branch -ha branch_value archive_value

Printed information contain bash colour codes. They probably wouldn't work in some shells.

__More information and tutorial soon!__
