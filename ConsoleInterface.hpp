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

class ConsoleInterface
{
public:
	ConsoleInterface(int, char**);
	~ConsoleInterface();

	struct param
	{
		param(const char * _name, bool _useDash = true) : value(NULL), isSet(false), isLong(false), useDash(_useDash)
		{
			if (_name == NULL)
				throw ConsoleInterfaceException_NullName();
			strcpy(name, _name);
			size_t nameLen = strlen(_name);
			if (nameLen > 1)
			{
				isLong = true;
			}
			else if (strlen(_name) == 1)
			{
				isLong = false;
			}
		}
		~param()
		{
			delete name;
			delete value;
		}
		char * name;
		char * value;
		bool isSet;
		bool isLong;
		bool useDash;
	};
	
	void AddParam(const char *, bool = true);

	bool IsParam(const char *);
	char * GetParamValue(const char *);
	param * GetParam(size_t);
	param * GetParam(const char *);

	virtual void Process();
private:
	int _argc;
	char ** _argv;
	std::vector<param*> _params;

	std::vector<param*>::iterator  _searchByName(const char *);
};

#endif
