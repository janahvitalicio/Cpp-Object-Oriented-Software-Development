// Name:                Janah Vitalicio
// Date of completion:  October 10, 2019

#include <algorithm>
#include <string>
#include <iomanip>
#include <regex>
#include <functional>

#include "Book.h"

namespace sdds {

	Book::Book() {
		mAuthor = "";
		mTitle = "";
		mCountry = "";
		mYear = 0;
		mPrice = 0.0;
		mDesc = "";
	}

	// A query that returns the title of the book
	const std::string& Book::title() const {
		return mTitle;
	}

	// A query that returns the publication country
	const std::string& Book::country() const {
		return mCountry;
	}

	// A query that returns the publication year
	const size_t& Book::year() const {
		return mYear;
	}

	// Returns the price by referene, allowing you to update the price
	double& Book::price() {
		return mPrice;
	}

	// Constructor that receives the book as a string
	Book::Book(const std::string& strBook) {
		std::string tempBook = strBook;
		std::string::size_type len = 0; // Stores the length of the token string

		// Extract the information
		std::string::size_type a[6] = {};
		a[0] = 0;

		for (int i = 0; i < 6; i++) {
			// Finds the next comma (until last comma only)
			if (i == 0) {
				a[i + 1] = tempBook.find(",");
			}
			else if (i < 5) {
				a[i + 1] = tempBook.find(",", a[i] + 1);
			}

			// Length of the token string
			if (i < 5) {
				len = a[i + 1] - a[i];
			}

			if (i == 0) {
				mAuthor = tempBook.substr(a[i], len);
				mAuthor = std::regex_replace(mAuthor, std::regex("^ +| +$|( ) +"), "");
			}
			if (i == 1) {
				mTitle = tempBook.substr(a[i] + 1, len - 1);
				mTitle = std::regex_replace(mTitle, std::regex("^ +| +$|( ) +"), "");
			}
			else if (i == 2) {
				mCountry = tempBook.substr(a[i] + 1, len - 1);
				mCountry = std::regex_replace(mCountry, std::regex("^ +| +$|( ) +"), "");
			}
			else if (i == 3) {
				std::string tempPrice = "";
				tempPrice = tempBook.substr(a[i] + 1, len - 1);
				tempPrice = std::regex_replace(tempPrice, std::regex("^ +| +$|( ) +"), "");
				mPrice = std::stod(tempPrice);
			}
			else if (i == 4) {
				std::string tempYear = "";
				tempYear = tempBook.substr(a[i] + 1, len - 1);
				tempYear = std::regex_replace(tempYear, std::regex("^ +| +$|( ) +"), "");
				mYear = std::stoi(tempYear);
			}
			else if (i == 5) {
				mDesc = tempBook.substr(a[i] + 1);
				mDesc = std::regex_replace(mDesc, std::regex("^ +| +$|( ) +"), "");
			}
		}
	}

	void Book::display(std::ostream& os) const {
		os << std::setw(20) << mAuthor << " | "
			<< std::setw(22) << mTitle << " | "
			<< std::setw(5) << mCountry << " | "
			<< std::setw(4) << mYear << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << mPrice << " | " 
			<< mDesc << std::endl;

	}

	std::ostream& operator<<(std::ostream& os, Book b) {
		b.display(os);

		return os;
	}
}