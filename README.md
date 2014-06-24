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
3. Run `Process` method.
4. __Advanced checking options' statuses and values are being developed ;)__ By the time they will be ready you can use `GetOptions` method and `for` loop. `Option` is a `struct` so all its elements are public.

Samples
-------

You can check sample application which use `ConsoleInterface` in `tests` directory. To compile whole project you should use Makefiles. Running these commands will allow you to test library.

	make all
	cd tests
	make all
	./ConsoleInterfaceTest --branch -ha branch_value archive_value < dataset

__More information and tutorial soon!__
