// Name:                Janah Vitalicio
// Date of completion:  Sept. 18, 2019
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

	String::String() {
		jv_string = nullptr;
	}

	String::String(const char* string) {
		// Checks if the string is a null address and then sets it to an null pointer
		if (string == nullptr) {
			jv_string = nullptr;
		}
		// Copies the string into an instance variable
		else {
			jv_string = new char[g_maxSize + 1];
			for (unsigned int i = 0; i < g_maxSize; i++) {
				jv_string[i] = string[i];
			}
			jv_string[g_maxSize] = '\0';
		}
	}

	void String::display(std::ostream& os) const {
		os << jv_string;
	}

	String::String(const String& other) {
		// Checks if the string is a null address and then sets it to an empty string
		if (other.jv_string == nullptr) {
			jv_string = nullptr;
		}
		else {
			// Allocate dynamic memory for jv_string
			jv_string = new char[g_maxSize + 1];
			for (unsigned int i = 0; i < g_maxSize; i++) {
				jv_string[i] = other.jv_string[i];
			}
			jv_string[g_maxSize] = '\0';
		}
	}

	String& String::operator=(const String& other) {
		// Check for self-assignment
		if (this != &other) {
			// Deallocate previously allocated dynamic memory
			delete[] jv_string;
			// If needed, allocate new dynamic memory
			if (other.jv_string != nullptr) {
				jv_string = new char[g_maxSize + 1];
				for (unsigned int i = 0; i < g_maxSize; i++) {
					jv_string[i] = other.jv_string[i];
				}
			}
			else {
				jv_string = nullptr;
			}
		}
		return *this;
	}

	String::~String() {
		delete[] jv_string; // Deallocate the memory allocated for the string array
		jv_string = nullptr;
	}

	ostream& operator<<(std::ostream& os, String& str) {
		os << counter++ << ": ";
		str.display(os);
		return os;
	}
	
}