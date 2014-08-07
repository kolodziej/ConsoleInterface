#ifndef CI_VERSION_HPP
#define CI_VERSION_HPP
#include <string>
#include <cstring>
#define CI_VERSION 10100

namespace CI
{
	struct Version
	{
		static const unsigned int ver;
		static const unsigned int IntVersion()
		{
			return ver;
		}
		static std::string StringVersion()
		{
			char cstr[10];
			sprintf(cstr, "v%d.%d.%d", (ver/10000), (ver/100) % 100, (ver % 100));
			return std::string(cstr);
		}
	};

	const unsigned int Version::ver = CI_VERSION;
}

#endif
