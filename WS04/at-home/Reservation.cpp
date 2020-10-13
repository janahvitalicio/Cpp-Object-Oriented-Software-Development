// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "Reservation.h"

namespace sdds {

	// Default constructor
	Reservation::Reservation() {
		mReservationID = "";
		mName = "";
		mEmail = "";
		mNumPeople = 0;
		mDay = 0;
		mHour = 0;
	}

	// Constructor that receives the reservation as a string
	Reservation::Reservation(const std::string& m_res) {
		std::string tempRes = m_res;
		std::string::size_type len = 0;

		// Erases all spaces
		tempRes.erase(std::remove_if(tempRes.begin(), tempRes.end(), ::isspace), tempRes.end());

		// Extract the information
		std::string::size_type n1 = tempRes.find(":");
		mReservationID = tempRes.substr(0, n1);
		std::string::size_type a[5] = {};
		a[0] = n1;

		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				a[i + 1] = tempRes.find(",");
			}
			// Finds the next comma (until last comma only)
			else if (i < 4) {
				a[i + 1] = tempRes.find(",", a[i] + 1);
			}

			len = a[i + 1] - a[i];

			if (i == 0) {
				mName = tempRes.substr(a[i] + 1, len - 1);
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
				mHour = std::stoi(tempRes.substr(a[i] + 1));
			}
		}
	}

	std::string Reservation::getResID() const {
		return mReservationID;
	}

	bool Reservation::operator==(const Reservation& src) {
		if (mReservationID == src.mReservationID) {
			return true;
		}
		else {
			return false;
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