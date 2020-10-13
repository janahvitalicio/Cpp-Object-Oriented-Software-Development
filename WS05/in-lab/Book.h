// Name:                Janah Vitalicio
// Date of completion:  October 10, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {

	class Book {
		std::string mAuthor;
		std::string mTitle;
		std::string mCountry;
		size_t mYear;
		double mPrice;
		std::string mDesc;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream&, Book);
	};
}

#endif