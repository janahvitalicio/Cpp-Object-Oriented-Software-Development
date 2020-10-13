// Name:                Janah Vitalicio
// Date of completion:  November 17, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

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