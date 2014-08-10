#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>

#ifdef DEBUG
	#define Log(x) std::clog << x << std::endl;
#else
	#define Log(x)
#endif
#endif
