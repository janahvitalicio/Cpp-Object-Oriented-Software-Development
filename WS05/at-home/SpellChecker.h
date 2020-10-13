// Name:                Janah Vitalicio
// Date of completion:  October 17, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[5];
		std::string m_goodWords[5];
		size_t m_size;

	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}

#endif