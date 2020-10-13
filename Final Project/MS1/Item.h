// Name:                Janah Vitalicio
// Date of completion:  November 17, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <string>

#include "Utilities.h"

class Item {
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	static size_t m_widthField;
public:
	Item(const std::string&);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};


#endif