// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "String.h"

using namespace std;

namespace sdds
{
	void process(const char* str)
	{
		String a = String(str);
		std::cout << a << std::endl;
	}
}
