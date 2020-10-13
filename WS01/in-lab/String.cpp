// Name:                Janah Vitalicio
// Date of completion:  Sept. 12, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace sdds
{
	unsigned int g_maxSize = 3; // Global variable
	static int counter = 1; // Static variable for counter

	String::String(const char* string) {
		// Checks if the string is a null address and then sets it to an empty string
		if (string == nullptr) {
			jv_string[0] = '\0';
		}
		// Copies the string into an instance variable
		else {
			strncpy(jv_string, string, g_maxSize);
			jv_string[3] = '\0';
		}
	}

	void String::display(std::ostream& os) const {
		os << jv_string;
	}

	ostream& operator<<(std::ostream& os, String& str) {
		os << counter++ << ": ";
		str.display(os);
		return os;
	}

}