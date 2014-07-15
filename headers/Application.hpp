#ifndef CI_APPLICATION_HPP
#define CI_APPLICATION_HPP
#include "Option.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

namespace CI
{
	class Application
	{
		public:
			Application(int, char**);
			~Application();

			void AddOption(char, std::string, bool);
			void AddOption(Option*);
			bool IsOptionSet(char);
			bool IsOptionSet(std::string &);
			std::string & GetOptionValue(char);
			std::string & GetOptionValue(std::string &);
			std::vector<Option*> & GetOptions();
			std::vector<std::string> & GetArguments();

			void Process() throw(Exception, Exception_OptionNotExists, Exception_InvalidOptionName, Exception_OptionHasNotValue);

		private:
			int argc;
			char ** argv;
			Option ** value_queue;
			int queue_b, queue_e;
			std::vector<Option*> options;
			std::vector<std::string> arguments;

			void _ProcessShort(const char *);
			void _ProcessLong(const char *);
			void _ProcessValue(const char*);
			void _ProcessArgument(const char *);

			bool _ProcessOption(char);
			bool _ProcessOption(std::string);

			Option * _SearchOption(char) throw(Exception_OptionNotExists);
			Option * _SearchOption(std::string &) throw(Exception_OptionNotExists);
	};
}
#endif
