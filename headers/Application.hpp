#ifndef CI_APPLICATION_HPP
#define CI_APPLICATION_HPP
#include "Option.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>
#include <memory>
#include <deque>
#include <stdexcept>

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

			void AddOption(char, std::string, bool, bool = false) throw(OptionExceptionPtr);
			void AddOption(std::shared_ptr<Option>) throw(OptionExceptionPtr);
			bool IsOptionSet(char);
			bool IsOptionSet(std::string &);
			std::shared_ptr<Option> GetOption(char);
			std::shared_ptr<Option> GetOption(std::string);
			std::string GetOptionValue(char, std::string = std::string()) throw(OptionExceptionPtr);
			std::string GetOptionValue(std::string, std::string = std::string()) throw(OptionExceptionPtr);
			std::string GetArgument(size_t) throw(std::out_of_range);
			std::vector<std::shared_ptr<Option>> & GetOptions();
			std::vector<std::string> & GetArguments();

			void Process() throw(ExceptionPtr, OptionExceptionPtr);

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

			std::shared_ptr<Option> _SearchOption(char) throw(OptionExceptionPtr);
			std::shared_ptr<Option> _SearchOption(std::string &) throw(OptionExceptionPtr);
	};
}
#endif
