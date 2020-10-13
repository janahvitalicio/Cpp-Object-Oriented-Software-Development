// Name:                Janah Vitalicio
// Date of completion:  October 17, 2019

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <regex>

#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker() {
		m_badWords[0] = '\0';
		m_goodWords[0] = '\0';
		m_size = 0;
	}

	// A constructor that receives as a parameter the name of the file that
	// Contains the misspelled words
	SpellChecker::SpellChecker(const char* filename) {
		std::string temp = "";
		std::ifstream file(filename);
		size_t p1 = 0; // Position1
		size_t p2 = 0; // Position2
		m_size = 0;

		if (file.is_open()) {
			do {
				std::getline(file, temp);

				p1 = 0;
				p2 = temp.find(' ');

				m_badWords[m_size] = temp.substr(p1, p2);
				m_goodWords[m_size] = temp.substr(p2);
				m_goodWords[m_size] = std::regex_replace(m_goodWords[m_size], std::regex("^ +| +$|( ) +|"), "");
				m_goodWords[m_size] = std::regex_replace(m_goodWords[m_size], std::regex("\r\n|\r|\n"), "");

				m_size++;
			} while (file.good() && m_size < 5);
		}
		else {
			throw "Bad file name!";
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		size_t position = 0;

		for (size_t i = 0; i < m_size; i++) {
			position = text.find(m_badWords[i]);
			if (position != text.npos) {
				while (position != text.npos) {
					text.replace(position, m_badWords[i].length(), m_goodWords[i]);
					position = text.find(m_badWords[i]);
				}
			}
		}
	}

}