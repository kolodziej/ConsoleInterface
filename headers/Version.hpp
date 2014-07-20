#ifndef CI_VERSION_HPP
#define CI_VERSION_HPP
#include <string>
#include <cstring>

namespace CI
{
	struct Version
	{
		const unsigned int ver;
		Version() : ver(10001) {}
		const unsigned int IntVersion() const
		{
			return ver;
		}
		std::string StringVersion()
		{
			char cstr[10];
			sprintf(cstr, "v.%d.%d.%d", (ver/10000), (ver/100) % 100, (ver % 100));
			return std::string(cstr);
		}
	};
}

#endif
