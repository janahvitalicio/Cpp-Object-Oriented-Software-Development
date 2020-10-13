// Name:                Janah Vitalicio
// Date of completion:  November 17, 2019

#include <iostream>

#include "Utilities.h"

size_t Utilities::m_widthField = 1; // Default value is 1
char Utilities::m_delimiter = '\0';

// Sets the field width of the current object to the value of the parameter
void Utilities::setFieldWidth(size_t w) {
	this->m_widthField = w;
}

// Returns the field width of the current object
size_t Utilities::getFieldWidth() const {
	return this->m_widthField;
}

// Extracts tokens from the first parameter
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t nPos = str.find(m_delimiter, next_pos + 1);         // Finds the next position of delimiter starting after next_pos
	size_t length = nPos - next_pos;                           // Length of token
	std::string token = str.substr(next_pos + 1, length - 1);  // Extract token in between next_pos and nPos
	next_pos = nPos;                                           // Sets next_pos for next delimiter position (nPos)

	more = (token.length() > 0) ? true : false;

	if (more == false) {
		throw std::string("Invalid token!");                   // Throws an exception if there are two delimiters with
	}                                                          // No token between them

	return token;
}

void Utilities::setDelimiter(const char d) {
	m_delimiter = d;
}

const char Utilities::getDelimiter() const {
	return this->m_delimiter;
}
