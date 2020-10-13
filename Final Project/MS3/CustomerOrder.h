// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef CUSTOMER_ORDER_H
#define CUSTOMER_ORDER_H

#include <string>
#include "Item.h"
#include "Utilities.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

	std::string m_name;          // Name of customer
	std::string m_product;       // Name of product being assembled
	unsigned int m_cntItem;      // Count of number of items for the customer's order
	ItemInfo** m_lstItem;        // Array of pointers; dynamically allocated object of ItemInfo
	static size_t m_widthField;  // Max width of a field

public:
	CustomerOrder();
	CustomerOrder(std::string&);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete; // Does not allow copy operations
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;
};

#endif