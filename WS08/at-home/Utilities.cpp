// Name:                Janah Vitalicio
// Date of completion:  November 18, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// Builds a list of products using raw pointers
		// For every description, it loops through every price
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* prod = new Product(desc[i].desc, price[j].price);
					prod->validate();
					priceList += prod;
					delete prod;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// Builds a list of products using smart pointers
		// For every description, it loops through every price
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> prod (new Product(desc[i].desc, price[j].price));
					prod->validate();
					priceList += prod;
				}
			}
		}

		return priceList;
	}
}