/* ConsoleInterface class
 * ConsoleInterface is a class for C++ applications
 * which provides a bunch of simple tools for console applications.
 * ConsoleInterface interprets application startup parameters passed
 * using char ** argv. For more information check README file.
 *
 * @author: Kacper Kołodziej
 * @email: poczta@kacperkolodziej.com
 * @url: http://kacperkolodziej.com
*/

#ifndef CONSOLE_INTERFACE_HPP_
#define CONSOLE_INTERFACE_HPP_
#include <vector>
#include <cstdlib>
#include <cstring>
#include <exception>

struct ConsoleInterfaceException : std::exception
{
	virtual const char * what() const throw()
	{
		return "ConsoleInterface problem has been detected!\n";
	}
};
struct ConsoleInterfaceException_NullName : ConsoleInterfaceException
{
	virtual const char * what() const throw()
	{
		return "Name must not be null!\n";
	}
};
struct ConsoleInterfaceException_OptionNotDefined : ConsoleInterfaceException
{
	virtual const char * what() const throw()
	{
		return "Option is not defined!\n";
	}
};
struct ConsoleInterfaceException_OptionNotExists : ConsoleInterfaceException
{
	virtual const char * what() const throw()
	{
		return "Option does not exists!\n";
	}
};
struct ConsoleInterfaceException_ValueNotDefined : ConsoleInterfaceException
{
	virtual const char * what() const throw()
	{
		return "Value for one or more options isn't defined!\n";
	}
};

class ConsoleInterface
{
public:
	ConsoleInterface(int, char**);
	~ConsoleInterface();

	struct option
	{
		option(const char * _name, bool _hasValue = false) : name(_name), value(NULL), isSet(false), hasValue(_hasValue)
		{
			if (name == NULL)
				throw ConsoleInterfaceException_NullName();
		}
		~option()
		{
			//if (value != NULL)
				//delete value;
		}
		const char * name;
		char * value;
		bool isSet;
		bool hasValue;

		int operator==(const char * c)
		{
			if (strcmp(c, name) == 0)
				return 1;

			return 0;
		}
		int operator!=(const char * c)
		{
			if (strcmp(c, name) == 0)
				return 0;

			return 1;
		}
	};
	
	void AddOption(const char *, bool = false);

	bool IsOption(const char *);
	option * GetOption(const char *);
	virtual void Process();
private:
	int _argc;
	char ** _argv;
	std::vector<option*> _options;
	std::vector<char*> _arguments;

	std::vector<option*>::iterator _search(const char *) throw(ConsoleInterfaceException_OptionNotExists);
};

#endif
