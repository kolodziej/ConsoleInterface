#ifndef CI_APPLICATION_HPP
#define CI_APPLICATION_HPP
#include "Option.hpp"
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
			std::vector<Option*> & GetOptions();

			bool * Processed() const;
			void Process();

		private:
			int argc;
			char ** argv;
			Option ** value_queue;
			int queue_b, queue_e;
			std::vector<Option*> options;

			void _ProcessShort(const char *);
			void _ProcessLong(const char *);
			void _ProcessValue(const char*);

			bool _ProcessOption(char);
			bool _ProcessOption(std::string);
	};
}
#endif
