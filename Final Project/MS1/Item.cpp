// Name:                Janah Vitalicio
// Date of completion:  November 17, 2019

#include <iostream>
#include <iomanip>
#include <string>

#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;

Item::Item(const std::string& rec) {
	Utilities util;
	bool more = false;
	size_t pos = rec.find(util.getDelimiter());                     // Find position of first delimiter
	m_name = rec.substr(0, pos);
	m_serialNumber = std::stoi(util.extractToken(rec, pos, more));
	m_quantity = std::stoi(util.extractToken(rec, pos, more));
	m_description = util.extractToken(rec, pos, more);

	util.setFieldWidth(m_name.length());                            // Uses length of name to set m_widthField to its max value
	if (util.getFieldWidth() > m_widthField) {                      // Updates Item::m_widthField to the maximum value
		m_widthField = util.getFieldWidth();                        // of Item::m_widthField and Utilities::m_widthField
	}
}

const std::string& Item::getName() const {
	return this->m_name;
}

const unsigned int Item::getSerialNumber() {
	unsigned int temp = m_serialNumber;
	m_serialNumber++;
	return temp;
};

const unsigned int Item::getQuantity() {
	return this->m_quantity;
};

void Item::updateQuantity() {
	if (m_quantity != 0) {
		m_quantity--;
	}
}

void Item::display(std::ostream& os, bool full) const {
	if (full == false) {
		os << std::left << std::setw(m_widthField) << m_name << " ["
			<< std::right << std::setfill('0') << std::setw(6) << m_serialNumber
			<< std::setfill(' ') << "]" << std::endl;
	}
	else {
		os << std::left << std::setw(m_widthField) << m_name << " ["
			<< std::right << std::setfill('0') << std::setw(6) << m_serialNumber << std::setfill(' ') << "] Quantity: "
			<< std::left << std::setw(m_widthField) << m_quantity << " Description: " << m_description << std::endl;
	}
}
