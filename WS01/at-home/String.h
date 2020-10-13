// Name:                Janah Vitalicio
// Date of completion:  Sept. 18, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_STRING_H
#define SDDS_STRING_H

#include <iostream>

namespace sdds
{
	extern unsigned int g_maxSize;

	class String {
		char* jv_string; // Holds C-style null-terminated characters of any length
						 // Including null byte terminator
	public:
		String();
		String(const char*);
		void display(std::ostream&) const;
		String(const String&); // Copy constructor
		String& operator=(const String&); // Copy assignment operator
		~String(); // Destructor
	};

	std::ostream& operator<<(std::ostream&, String&);
}

#endif