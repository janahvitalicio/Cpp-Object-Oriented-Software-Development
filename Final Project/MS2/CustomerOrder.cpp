// Name:                Janah Vitalicio
// Date of completion:  November 24, 2019

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

// Default constructor
CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = { nullptr };
}

// Custom constructor that takes as a parameter a reference to a string containing a single record from the input file
CustomerOrder::CustomerOrder(std::string& rec) {
	Utilities util;                              // Uses a Utilities object to extract the tokens and populate current instance
	bool more = false;
	size_t pos = rec.find(util.getDelimiter());  // Find position of first delimiter
	std::vector<ItemInfo*> temp;

	m_name = rec.substr(0, pos);
	util.setFieldWidth(m_name.length());         // Uses length of name to set m_widthField to its max value
	if (util.getFieldWidth() > m_widthField) {   // Updates CustomerOrder::m_widthField if the value stored there
		m_widthField = util.getFieldWidth();     // Is smaller than the value stored in Utilities::m_widthField
	}

	m_product = util.extractToken(rec, pos, more);
	m_cntItem = std::count(rec.begin(), rec.end(), util.getDelimiter()) - 1;

	size_t count = m_cntItem;
	while (count != 0) {
		temp.push_back(new ItemInfo(util.extractToken(rec, pos, more)));
		count--;
	}

	m_lstItem = new ItemInfo * [m_cntItem];

	if (m_cntItem >= 1) {
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = std::move(temp[i]);
		}
	}

}

// Copy constructor: not allowed; throws an exception
CustomerOrder::CustomerOrder(const CustomerOrder&) {
	throw "ERROR";
}

// Move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}

// Move assignment operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (this != &src) {
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;

		src.m_lstItem = nullptr;
	}
	return *this;
}

// Destructor
CustomerOrder::~CustomerOrder() {
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

// Returns the ItemInfo::m_fillState of the item specified as a parameter
// if the item doesn't exist in the order, it returns true
bool CustomerOrder::getItemFillState(std::string item) const {
	// Search the m_lstItem for the item (given parameter)
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item) {
			if (m_lstItem[i]->m_fillState == false) {
				return false;
			}
		}
	}
	return true;
}

// Returns true if all the items in the order have been filled; false otherwise
bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) {
			return false;
		}
	}
	return true;
}

// Fills the item in the current order that corresponds to the item passed into the function
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() > 0) {
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "["
					<< m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "["
					<< m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}

// Displays the state of the current object
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber
			<< "] " << std::setfill(' ')
			<< std::setw(m_widthField) << m_lstItem[i]->m_itemName << "     - ";

		if (m_lstItem[i]->m_fillState) {
			os << "FILLED" << std::endl;
		}
		else {
			os << "MISSING" << std::endl;
		}
	}
}