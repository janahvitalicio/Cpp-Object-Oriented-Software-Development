// Name:                Janah Vitalicio
// Date of completion:  October 3, 2019

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "Reservation.h"

#define NUMELEMNTS 5 // Number of elements in the string
                     // Reservation id, name, email, # of people, day, hour

namespace sdds {

	// Default constructor
	Reservation::Reservation() {
		mReservationID = nullptr;
		mName = nullptr;
		mEmail = nullptr;
		mNumPeople = 0;
		mDay = 0;
		mHour = 0;
	}

	
	Reservation::Reservation(const std::string& m_res) {
		std::string tempRes = m_res;
		std::string::size_type len;

		// Removes all spaces from the beginning and end of the string
		tempRes.erase(std::remove_if(tempRes.begin(), tempRes.end(), ::isspace), tempRes.end());

		std::string::size_type n1 = tempRes.find(":");
		mReservationID = tempRes.substr(0, n1);
		std::string::size_type a[NUMELEMNTS - 1] = {}; // excluding reservation ID
		a[0] = n1;

		// Loops through the token string to extract information and store it to the class member variables
		// Finds the position of first delimeter, comma, and the second to calculate the length of the word
		// Extract the information starting at the position of the first found comma until the calculated length
		for (int i = 0; i < 5; i++) {
			if(i == 0){
				a[i + 1] = tempRes.find(",");
			}
			else {
				a[i + 1] = tempRes.find(",", a[i] + 1);
			}

			len = a[i + 1] - a[i];

			if (i == 0) {
				mName = tempRes.substr(a[i] + 1, len - 1); // a[i] + 1 --after the comma  // len - 1 --excluding the comma
			}
			else if (i == 1) {
				mEmail = tempRes.substr(a[i] + 1, len - 1);
			}
			else if (i == 2) {
				mNumPeople = std::stoi(tempRes.substr(a[i] + 1, len - 1));
			}
			else if (i == 3) {
				mDay = std::stoi(tempRes.substr(a[i] + 1, len - 1));
			}
			else if (i == 4) {
				mHour = std::stoi(tempRes.substr(a[i] + 1, len - 1));
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, Reservation rs) {

		os << "Reservation " << rs.mReservationID << ": " << std::right << std::setw(10) << rs.mName << "  "
			<< std::left << std::setw(20) << "<" + rs.mEmail + ">";

		if (rs.mHour >= 6 && rs.mHour <= 9) {
			os << "    Breakfast on day ";
		}
		else if (rs.mHour >= 11 && rs.mHour <= 15) {
			os << "    Lunch on day ";
		}
		else if (rs.mHour >= 17 && rs.mHour <= 21) {
			os << "    Dinner on day ";
		}
		else {
			os << "    Drinks on day ";
		}

		os << rs.mDay << " @ " << rs.mHour << ":00 for " << rs.mNumPeople << " people."
			<< std::endl;

		return os;
	}

}