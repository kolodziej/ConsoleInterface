#ifndef CI_APPLICATION_HPP
#define CI_APPLICATION_HPP
#include "Option.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>
#include <memory>
#include <deque>

namespace CI
{
	class Application
	{
		public:
			enum Settings { 
				RequireValue = 1 << 0,
				NoArguments = 1 << 1,
			};
			Application(int, char**, unsigned int = 0);
			~Application();

			void AddOption(char, std::string, bool) throw(Exception_InvalidOptionName);
			void AddOption(std::shared_ptr<Option>) throw(Exception_InvalidOptionName);
			bool IsOptionSet(char);
			bool IsOptionSet(std::string &);
			std::shared_ptr<Option> GetOption(char);
			std::shared_ptr<Option> GetOption(std::string);
			std::string GetOptionValue(char, std::string = std::string()) throw(Exception_OptionHasNotValue);
			std::string GetOptionValue(std::string, std::string = std::string()) throw(Exception_OptionHasNotValue);
			std::vector<std::shared_ptr<Option>> & GetOptions();
			std::vector<std::string> & GetArguments();

			void Process() throw(Exception, Exception_OptionNotExists, Exception_InvalidOptionName, Exception_OptionHasNotValue);

		private:
			int argc;
			char ** argv;
			unsigned int settings;
			std::deque<std::shared_ptr<Option>> queue;
			std::vector<std::string> argv_params;
			std::vector<std::shared_ptr<Option>> options;
			std::vector<std::string> arguments;

			void _ProcessShort(const char *);
			void _ProcessLong(const char *);
			void _ProcessValue(const char *);
			void _ProcessArgument(const char *);

			bool _ProcessOption(char);
			bool _ProcessOption(std::string);

			bool _CheckSettings(Settings);

			std::shared_ptr<Option> _SearchOption(char) throw(Exception_OptionNotExists);
			std::shared_ptr<Option> _SearchOption(std::string &) throw(Exception_OptionNotExists);
	};
}
#endif
