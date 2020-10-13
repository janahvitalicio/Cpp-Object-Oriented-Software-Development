// Name:                Janah Vitalicio
// Date of completion:  October 17, 2019

#include <iostream>
#include <iomanip>
#include <regex>

#include "Movie.h"

#define NUMELEM 3

namespace sdds {
	Movie::Movie() {
		mTitle = "";
		mYear = 0;
		mDesc = "";
	}

	const std::string& Movie::title() const {
		return mTitle;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string tempMovie = strMovie;
		std::string::size_type len = 0; // Stores the length of the token string

		// Extract the information
		std::string::size_type a[NUMELEM] = {};
		a[0] = 0;

		for (int i = 0; i < NUMELEM; i++) {
			// Finds the next comma (until last comma only)
			if (i == 0) {
				a[i + 1] = tempMovie.find(",");
			}
			else if (i < (NUMELEM - 1)) {
				a[i + 1] = tempMovie.find(",", a[i] + 1);
			}

			// Length of the token string
			if (i < (NUMELEM - 1)) {
				len = a[i + 1] - a[i];
			}

			if (i == 0) {
				mTitle = tempMovie.substr(a[i], len);
				mTitle = std::regex_replace(mTitle, std::regex("^ +| +$|( ) +"), "");
			}
			if (i == 1) {
				std::string tempYear = "";
				tempYear = tempMovie.substr(a[i] + 1, len - 1);
				tempYear = std::regex_replace(tempYear, std::regex("^ +| +$|( ) +"), "");
				mYear = std::stoi(tempYear);
			}
			else if (i == 2) {
				mDesc = tempMovie.substr(a[i] + 1);
				mDesc = std::regex_replace(mDesc, std::regex("^ +| +$|( ) +"), "");
			}
		}
	}

	void Movie::display(std::ostream& os) const {
		os << std::setw(40) << mTitle << " | "
			<< std::setw(4) << mYear << " | "
			<< mDesc << std::endl;

	}

	std::ostream& operator<<(std::ostream& os, Movie m) {
		m.display(os);

		return os;
	}

}