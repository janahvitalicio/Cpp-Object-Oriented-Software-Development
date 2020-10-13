// Name:                Janah Vitalicio
// Date of completion:  Sept. 12, 2019
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
		char jv_string[4]; // Holds 3 C-style null-terminated characters
		                   // Including null byte terminator
	public:
		String(const char*);
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, String&);
}

#endif