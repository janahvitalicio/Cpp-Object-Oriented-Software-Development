// Name:                Janah Vitalicio
// Date of completion:  October 17, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {

	class Movie {
		std::string mTitle;
		int mYear;
		std::string mDesc;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		void display(std::ostream& os) const;

		friend std::ostream& operator<<(std::ostream&, Movie);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(mTitle);
			spellChecker(mDesc);
		}
	};
}

#endif