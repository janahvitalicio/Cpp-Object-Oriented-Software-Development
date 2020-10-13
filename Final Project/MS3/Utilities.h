// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>


class Utilities {
	static size_t m_widthField; // Length of token
	static char m_delimiter;

public:
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;
};


#endif